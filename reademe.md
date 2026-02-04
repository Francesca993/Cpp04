# Cos’è una classe astratta (in parole semplici)
Una classe astratta è una classe che:
* non rappresenta un oggetto concreto
* serve solo come modello / contratto
* non può essere istanziata
* In C++ una classe diventa astratta quando ha almeno una funzione pure virtual:
    - virtual void makeSound() const = 0;

- Il = 0 significa:
“Questa funzione DEVE esistere, ma io (classe base) NON la implemento”.

Perché Animal deve essere astratta
Chiediti questa cosa (logica, non C++):
👉 Ha senso creare un oggetto “Animal” generico?
Che verso fa un Animal?
Che tipo è?
Ha un Brain?
La risposta è: no.
Un Animal “generico” non esiste davvero: esistono Dog, Cat, ecc.

Quindi:
```c++
Animal a;      // concettualmente sbagliato
new Animal();  // concettualmente sbagliato
```
-> L’esercizio ti obbliga a far rispettare questa idea anche al compilatore.

## Separare “cos’è” da “come si comporta”
Animal dice:
“ogni animale DEVE fare un suono”
ma non dice quale
virtual void makeSound() const = 0;
Dog e Cat dicono come:
```c++
    void Dog::makeSound() const { ... }
    void Cat::makeSound() const { ... }
```
👉 Questo è design a interfaccia.

## Usare la classe base SOLO come interfaccia
Con Animal* puoi:
```c++
Animal* a = new Dog();
a->makeSound();   // funziona
```
Ma non puoi:
```c++
new Animal();     // vietato
```
👉 Animal diventa una promessa di comportamento, non un oggetto reale.

## Con Animal* → NO, non puoi accedere al Brain
Se hai:
```c++
Animal* a = new Dog();
```
puoi chiamare solo i metodi dichiarati in Animal:
```c++
a->makeSound();   // ✅ (pure virtual, ma implementata in Dog)
a->getType();     // ✅
a->printIdeas();  // ❌ NO: Animal non lo conosce
a->getBrain();    // ❌ NO
```
👉 Anche se l’oggetto reale è un Dog, il compilatore guarda il tipo statico (Animal*).
Questo è voluto: Animal è un’interfaccia astratta, non deve sapere nulla del Brain.
2️⃣ Con Dog* / Cat* → SÌ, puoi accedere al Brain
Se invece hai:
```c++
Dog* d = new Dog();
```
allora puoi fare:
```c++
d->printIdeas();     // ✅
d->getIdea(0);       // ✅
d->getBrain();       // ✅ (se esiste)
```
Perché il tipo statico è Dog*.
3️⃣ Caso chiave: hai Animal* ma sai che è un Dog
Qui entra in gioco il cast controllato.
```c++
Animal* a = new Dog();
if (Dog* d = dynamic_cast<Dog*>(a))
{
    d->printIdeas();   // ✅ ora sì
}
```
**Questo è l’unico modo corretto e sicuro per accedere a metodi specifici partendo da un puntatore alla classe astratta.**

ex02 vuole insegnare questa separazione netta:
Animal
interfaccia
contratto
comportamento comune
NON dettagli interni
Dog / Cat
implementazione concreta
dettagli (Brain, idee, ecc.)
Se Animal avesse getBrain():
Dog ok
Cat ok
Animal generico ❌ (che Brain avrebbe?)
Quindi è design sbagliato.

# “Con un puntatore alla classe astratta posso usare solo l’interfaccia. Per accedere ai dettagli dell’implementazione devo conoscere il tipo concreto.

# ex03: Separare cosa un oggetto È da cosa un oggetto PUÒ FARE, usando interfacce astratte.

# 1️⃣ I PERSONAGGI DELLA STORIA (molto semplice)
In ex03 ci sono 3 ruoli, non di più.
* **🧙‍♂️ Character**
👉 È chi combatte
    - Ha 4 slot.
    - Dentro ogni slot c’è una Materia.
    - Lui usa le Materia (use).
    - Lui non crea Materia.
📌 Pensa a un personaggio con 4 armi in tasca.
* **❄️ / 💊 Materia (AMateria, Ice, Cure)**
👉 È l’oggetto magico
    - Ice e Cure sono oggetti concreti.
    - AMateria è solo la base astratta.
    - Ogni Materia sa:
        * che tipo è ("ice", "cure")
        * cosa succede quando viene usata (use)
📌 Pensa a una singola magia o pozione.
* **🏭 MateriaSource**
👉 È la fabbrica
    - NON combatte
    - NON usa magie
    - NON va nell’inventario del Character
    - Serve solo per creare Materia
📌 Pensa a una macchina che costruisce magie.

### 2️⃣ Flusso reale (questa è la chiave)

🔹 MateriaSource crea
🔹 Character usa

**Esempio mentale:**
La fabbrica impara a costruire il ghiaccio
→ “So fare Ice”

La fabbrica costruisce una magia Ice
→ “Ecco una Ice nuova di zecca”

Il Character prende quella Ice
→ la mette nello slot

Il Character usa la Ice contro qualcuno
💥 Fine.

La fabbrica non c’entra più niente.
3️⃣ Allora a cosa serve IMateriaSource?

❓ Perché non usare direttamente MateriaSource?
Perché il subject VUOLE che impari questo concetto:
“Non mi interessa come viene creata una Materia,
mi interessa solo che qualcuno sappia crearla.”

IMateriaSource è:
👉 una promessa
👉 un contratto
Dice solo:
“Chiunque si chiami MateriaSource DEVE saper fare queste 2 cose”
imparare una Materia
crearne una nuova da un tipo
Non dice come.

### 4️⃣ Metafora finale

Tu nel codice fai:
```c++
IMateriaSource* src = new MateriaSource();
```
Stai dicendo:
“A me non interessa che caricatore è.
Basta che rispetti la presa.”
Questo serve per:
polimorfismo
esercitarsi con interfacce
capire perché servono i distruttori virtuali


❌ Character NON punta a MateriaSource
✅ Character punta a AMateria

❌ MateriaSource NON usa Materia
✅ MateriaSource le crea

❌ IMateriaSource NON è un oggetto vero
✅ È solo una regola


```c++
```