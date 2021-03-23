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

    void tick();

    void toggleHwLed();

    void setScanJunctionTemp(bool scanEnabled);
    int getTempValue();

protected:
    ModelListener* modelListener;

    int tickCounter;
    bool scanJunctionTemp;
};

#endif // MODEL_HPP
