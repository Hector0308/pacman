class TazoDorado
{
private:
    bool flotando;
public:
    TazoDorado() {

    }
    ~TazoDorado() {
      this -> flotando = false;
    }
      void Flotar(){
           this -> flotando = true;  

      }
    
};