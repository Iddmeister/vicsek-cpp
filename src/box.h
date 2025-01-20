#ifndef BOX_H
#define BOX_H

class Box {

    public:
        Box();
        Box(double lx, double ly, double x0, double y0);
        void setSides(double lx, double ly);
        void setOrigin(double x, double y);
        double getSidex();
        double getSidey();

    private:
        double sidex;
        double sidey;
        double x0;
        double y0;

};

#endif
