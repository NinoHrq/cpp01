#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

static void run_test(const std::string& s)
{
    std::cout << "=============================\n";
    std::cout << "Input: " << s << "\n";
    std::cout << "-----------------------------\n";
    ScalarConverter::convert(s);
    std::cout << std::endl;
}

int main()
{
    // 1) Cas de base (int)
    run_test("0");
    run_test("1");
    run_test("42");
    run_test("-42");
    run_test("97");      // 'a'
    run_test("32");      // space (affichable)
    run_test("31");      // non displayable
    run_test("127");     // DEL (souvent non displayable)
    run_test("128");     // char impossible

    // 2) Doubles
    run_test("0.0");
    run_test("42.0");
    run_test("-4.2");
    run_test("4.2");
    run_test("123456.789");

    // 3) Floats (suffixe f)
    run_test("0.0f");
    run_test("42.0f");
    run_test("-4.2f");
    run_test("4.2f");
    run_test("123456.789f");

    // 4) Pseudo-littéraux (obligatoires)
    run_test("nan");
    run_test("nanf");
    run_test("+inf");
    run_test("-inf");
    run_test("+inff");
    run_test("-inff");

    // 5) Char literal (obligatoire)
    run_test("'a'");
    run_test("'Z'");
    run_test("'0'");
    run_test("' '");     // espace

    // 6) Limites int (utile pour overflow)
    // (si ta conversion int est bien protégée, ça doit afficher "int: impossible")
    run_test("2147483647");   // INT_MAX
    run_test("-2147483648");  // INT_MIN
    run_test("2147483648");   // overflow
    run_test("-2147483649");  // overflow

    // 7) Entrées invalides (doivent être rejetées proprement)
    run_test("");
    run_test("+");
    run_test("-");
    run_test(".");
    run_test("..");
    run_test("4..2");
    run_test("42f");      // souvent considéré invalide (pas un float literal standard)
    run_test("4.2ff");
    run_test("abc");
    run_test("42abc");
    run_test("'ab'");     // invalide (taille != 3)
    run_test("''");       // invalide
    run_test("'\\n'");    // invalide dans ce sujet (escape, non demandé)

    return 0;
}
