#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

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
    int getWaga();
    int getPojemnosc();

protected:
    ModelListener* modelListener;

    int waga;
    int pojemnosc;
};

#endif // MODEL_HPP
