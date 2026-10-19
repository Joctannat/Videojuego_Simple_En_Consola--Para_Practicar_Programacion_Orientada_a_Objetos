#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Joctan L�pez / A0165

class Agente {
	private:
		float vida;
		float defensa;
	public:
		Agente();
		//virtual void ReEstadi();
		virtual float getvida()=0;
		virtual float getdefensa()=0;
		virtual void setvida(float _vida)=0;
};

Agente::Agente() {

}
////////////////////////////////////////////////////////
class Goblin :public Agente {
	private:
		float vida=90;
		float defensa=70;
	public:
		void Ataque() {
			cout << "Enemigo Goblin Ataca" << endl;
		}
		float getvida() override {
			return vida;
		}
		float getdefensa() override {
			return defensa;
		}
		void setvida(float _vida){
			vida = _vida;
			cout << "					La nueva vida es: " << vida<<endl;
		
		}
		void setdefensa(float _defensa) {
			defensa = _defensa;
		}


};
////////////////////////////////////////////////////////
class Esqueleto :public Agente {
	private:
		float vida=120;
		float defensa=50;
	public:
		void Ataque() {
			cout << "Enemigo Esqueleto Ataca" << endl;
		}
		float getvida() override {
			return vida;
		}
		float getdefensa() override {
			return defensa;
		}
		void setvida(float _vida) {
			vida = _vida;
			cout << "					La nueva vida es: " << vida << endl;

		}
};
//////////////////////////////////////////////////
class Lich :public Agente {
	private:
		float vida=200;
		float defensa=9.1;
	public:
		void Ataque() {
			cout << "Enemigo Lich Ataca" << endl;
		}
		float getvida() override {
			return vida;
		}
		float getdefensa() override {
			return defensa;
		}
		void setvida(float _vida) {
			vida = _vida;
			cout << "					La nueva vida es: " << vida << endl;

		}
};

//////////////////////////////////////////////////////
class Jugador :public Agente {
	private:
		int experiencia = 0;
		float vida=200;
		float defensa=30;
	public:
		string gameover();

		float getvida() override{
			return vida;
		}
		float getdefensa() override{
			return defensa;
		}
		void setvida(float _vida) {
			vida = _vida;
			cout << "					Tu nueva vida es: " << vida << endl;

		}
};

string Jugador::gameover() {
	if (getvida()<=0) {
		return "Fin del Juego";
		
	}
	else {
	    cout << "       " << endl;
	    cout << " " << endl;
	    cout << "  " << endl;
	    cout << " " << endl;
	    cout << " " << endl;
	    cout << " " << endl;
	    cout << " " << endl;
	    cout << " " << endl;

		return "Siguiente turno";
	}
}

///////////////////////////////////////////////////////









//// Inicia el Main

int main() {
	
	int ataq;
	
	float da�oG;
	float da�oE;
	float da�oL;

	float da�orec;
	float vidares;

	int AtaquePV=0;
	int HabJugador = 0;
	float nvida;
	int regeneracion;
	int HabEnemigos;
	float nuevdefensa;
	float nve;
	float hl;

	float atkJ=90;

	float vidafinalG;
	float vidafinalE;
	float vidafinalL;

	srand(time(NULL));

	Jugador jugador;
	Goblin goblin;
	Esqueleto esqueleto;
	Lich lich;

	cout << "Calabozos e Instancias" << endl;
	while (jugador.getvida() > 0) {
		
		cout << "Tu Vida: " << jugador.getvida() << "  " << "Tu Defensa: " << jugador.getdefensa() << endl;
		cout << "Tu Ataque: " << atkJ << endl;
		cout << " " << endl;
		cout << "Elige un enemigo para atacar //  1: Goblin  2: Esqueleto  3:Lich" << endl;
		cin >> ataq;
		system("cls");
		if (ataq == 1) {
			cout << "  " << endl;
			da�oG = atkJ - goblin.getdefensa();
			vidafinalG = goblin.getvida() - da�oG;
			cout << "					Da�o inflingido a Enemigo Goblin: " << da�oG << endl;
			goblin.setvida(vidafinalG);

		}

		else if (ataq == 2) {
			cout << "  " << endl;
			da�oE = atkJ - esqueleto.getdefensa();
			vidafinalE = esqueleto.getvida() - da�oE;
			cout << "					Da�o inflingido a enemigo Esqueleto: " << da�oE << endl;
			esqueleto.setvida(vidafinalE);

		}

		else if (ataq == 3) {
			cout << "  " << endl;
			da�oL = atkJ - lich.getdefensa();
			vidafinalL = lich.getvida() - da�oL;
			cout << "					Da�o inflingido a enemigo Lich: " << da�oL << endl;
			lich.setvida(vidafinalL);
		}

//////////////////////////////////////////////////////////////////////////////////////

		if (goblin.getvida() <= 0) {
			cout << "					Enemigo    Goblin Derrotado  " << endl;
			cout << "  " << endl;
		}
		if (esqueleto.getvida() <= 0) {
			cout << "					Enemigo    Esqueleto Derrotado  " << endl;
			cout << "  " << endl;
		}
		if (lich.getvida() <= 0) {
			cout << "					Enemigo    Lich Derrotado  " << endl;
			cout << "  " << endl;
		}
		if (goblin.getvida() <= 0 && esqueleto.getvida() <= 0 && lich.getvida() <= 0) {
			cout << "Ganaste";
			break;
		}

		///////////////////////////////////////////////////////////
		//Experiencia
		cout << " " << endl;
		cout << "Experiencia = Ataque + 0.5" << endl;
		atkJ = atkJ + 0.5;


///////////////////////////////////////////////////

/// Randomizar que enemigo ataca en cada turno

		AtaquePV = rand()%9;

		if (AtaquePV >= 0 && AtaquePV<3){
			if (goblin.getvida() <= 0) {
				cout << "El enemigo Goblin no puede atacar"<<endl;
			}
			else {
				goblin.Ataque();
				da�orec = 40 - jugador.getdefensa();
				vidares = jugador.getvida() - da�orec;
				jugador.setvida(vidares);
			}
		}

		else if (AtaquePV >= 3 && AtaquePV < 6) {
			if (esqueleto.getvida() <= 0) {
				cout << "El enemigo Esqueleto no puede atacar" << endl;
			}
			else {
				esqueleto.Ataque();
				da�orec = 60 - jugador.getdefensa();
				vidares = jugador.getvida() - da�orec;
				jugador.setvida(vidares);
			}
		}

		else if (AtaquePV >= 6 && AtaquePV < 9) {
			if (lich.getvida() <= 0) {
				cout << "El enemigo Lich no puede atacar" << endl;
			}
			else {
				lich.Ataque();
				da�orec = 88.88 - jugador.getdefensa();
				vidares = jugador.getvida() - da�orec;
				jugador.setvida(vidares);

			}
		
		}


/////////////////////////////////////////////////////
// Randomizar la activación de habiliades de los enemigos
		
		HabEnemigos = rand() % 9; 
		if (HabEnemigos >= 0 && HabEnemigos < 3) {
			cout << "Enemigo Goblin Activa su Habilidad: Defensa + 15" << endl;
			nuevdefensa=goblin.getdefensa() + 13;
			goblin.setdefensa(nuevdefensa);
		}

		else if (HabEnemigos >= 3 && HabEnemigos < 6) {
			cout << "Enemigo Esqueleto Activa su Habilidad" << endl;
			nve=esqueleto.getvida() + 30;
			esqueleto.setvida(nve);
		}
		else {
			cout << "Enemigo Lich Activa su Habilidad" << endl;
			hl = jugador.getvida() - 15;
			jugador.setvida(hl);
		}



///////////////////////////////////////////////

		HabJugador = rand()%11;

		if (HabJugador >= 4 && HabJugador <= 6) {
			regeneracion = 30 + rand() % 60;
		}

		if (HabJugador >= 4 && HabJugador <= 6) {
			nvida = jugador.getvida() + regeneracion;
			jugador.setvida(nvida);
			
			cout << " " << endl;
			cout << "					Habilidad Activada + "<< regeneracion << endl;
		}

		else {
			cout << " " << endl;
		}
		


		cout << jugador.gameover() << endl;
		cout << "   " << endl;
	} // Llave del While


} // Llave del main