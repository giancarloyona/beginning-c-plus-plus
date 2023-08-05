#ifndef BEGINNING_C_PLUS_PLUS_POLYMORPHISM_I_PRINTABLE_H_
#define BEGINNING_C_PLUS_PLUS_POLYMORPHISM_I_PRINTABLE_H_

class I_Printable {
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
 public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() = default;
};

#endif
