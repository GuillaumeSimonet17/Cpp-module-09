#include "RNP.cpp"
#include <cctype>

bool    is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "invalid number of args" << std::endl;
        return 0;
    }
    size_t i = 0;
    int    err = 0;
    RNP st;

    st.setStr(av[1]);
    while (i < st.getSize())
    {
        if (st.getC(i) != ' ')
        {
            if (!isdigit(st.getC(i)))
            {
                st.opera = st.getC(i);
                err = st.ft_calcul_polonish();
                if (err == 1)
                {
                    std::cout << "Error: not enough number in stack" << std::endl;
                    return 1;
                }
                else if (err == 2)
                {
                    std::cout << "Error: division by 0 impossible" << std::endl;
                    return 1;
                }
                else if (err == 3)
                {
                    std::cout << "Error: character invalid" << std::endl;
                    return 1;
                }

            }
            else
                st.addNodeInStack(st.getC(i));
        }
        i++;
    }
    if ( st.getStack().size() != 1)
    {
        std::cout << "Error: not enough operator" << std::endl;
        return 1;
    }
    std::cout << st.getTop() << std::endl; 
    return 0;
}
