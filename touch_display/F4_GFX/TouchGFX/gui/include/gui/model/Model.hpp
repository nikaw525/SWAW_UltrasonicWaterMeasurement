#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();
    void tick();
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void saveWaga(int saveWaga)
    {
    	waga = saveWaga;
    }

    void savePojemnosc(int savePojemnosc)
	{
		pojemnosc = savePojemnosc;
	}
    void saveWysokosc(int saveWysokosc)
	{
		wysokosc = saveWysokosc;
	}
    int getWaga();
    int getPojemnosc();
    int getWysokosc();

protected:
    ModelListener* modelListener;

    int waga;
    int pojemnosc;
    int wysokosc;
};

#endif // MODEL_HPP
