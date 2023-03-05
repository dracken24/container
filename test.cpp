#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v{1, 2, 3, 4, 5};
  
  std::cout << "La dernière valeur du vecteur est : " << v.back() << std::endl;
  
  v.push_back(6);
  
  std::cout << "La nouvelle dernière valeur du vecteur est : " << v.back() << std::endl;

  v.push_back(6745);
  
  std::cout << "La nouvelle dernière valeur du vecteur est : " << v.back() << std::endl;

  
  for (size_t i = 0; i < v.size(); i++)
		std::cout << "[" << v.at(i) << "] ";
  return 0;
}
