#ifndef ELF_H
#define ELF_H

class elf{
  public:

      // Constructor
      elf(int x_, int y_, int idx_);

      // Member functions
      void goBack();
      void print();
      void move();
      void consider(string order);
      ~elf(){};

      // Member variables
      int x;
      int y;
      int Px;
      int Py;
      int idx;
      char nextDir;

};

#endif // ELF_H
