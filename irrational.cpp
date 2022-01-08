#include <map>

#include "irrational.h"

void Irrational::Item::simplify()
{
    // case 1: coef or rational == 0
    if (coef == 0 || rational == 0)
    {
        coef = 0;
        rational = 1;
        power = 0;
    }

    // case 2: rational == 1
    if (rational == 1)
    {
        // coef not change
        // rational not change
        power = 0;
    }

    // case 3: power == 0
    if (power == 0)
    {
        // coef not change
        rational = 1;
        // power not change
    }

    // case 4: |power.num| > 1
    if (std::abs(power.num) > 1)
    {
        // coef not change
        for (int i = 1; i < std::abs(power.num); ++i)
        {
            rational *= rational;
        }
        power.num = (power.num > 0 ? 1 : -1);
        // power.den not change
    }

    // case 5: power.den > 1
    if (power.den > 1)
    {
        std::map<int, int> counter;
        int factor = 2;
        int r = rational;

        // decompose prime factor
        // 8^(1/3) -> fac 2: cnt 3
        // 12^(1/2) -> fac 2: cnt: 2, fac: 3, cnt: 1
        while (r > 1)
        {
            if (r % factor == 0)
            {
                ++counter[factor];
                r /= factor;
            }
            else
            {
                ++factor;
            }
        }

        // 8^(1/3):
        //    coef: 1, rational: 8, power: (1/3)
        // -> coef: 2, rational: 1, power: 0
        // 12^(1/2):
        //    coef: 1, rational: 12, power: 1/2
        // -> coef: 2, rational: 3, power: 1/2
        for (factor = 2; factor < rational; ++factor)
        {
            // √24 -> √(2*2*2*3) -> 2√6
            if (counter[factor] >= power.den)
            {
                int tmp = power.den;
                while (tmp != 0)
                {
                    rational /= factor;
                    --tmp;
                }

                if (power > 0)
                {
                    coef *= factor;
                }
                else if (power < 0)
                {
                    coef /= factor;
                }
            }
        }
        if (rational == 1)
        {
            power = 0;
        }
    }
}

Irrational::Item::Item(Fraction coef, int rational, Fraction power)
{
    this->coef = coef;
    this->rational = rational;
    this->power = power;

    simplify();
}

bool Irrational::Item::operator==(const Irrational::Item& item) const
{
    return coef == item.coef
           && rational == item.rational
           && power == item.power;
}

//// for list sort
//bool cmp(const Irrational::Item& first, const Irrational::Item& second)
//{
//    return first.rational > second.rational || first.power > second.power;
//}

//void Irrational::simplify()
//{
//    // step 1: single item
//    if (size == 1)
//    {
//        return;
//    }

//    // step 2: merge similar terms
//    list<Item> tmp;
//    while (irrational.size() != 0)
//    {
//        auto head = irrational.begin();
//        int coef = 0;
//        for (auto current = ++irrational.begin(); current != irrational.end(); ++current)
//        {
//            if (head->rational == current->rational && head->power == current->power)
//            {
//                coef += current->coef;
//                irrational.erase(current);
//            }
//        }
//        coef += head->coef;
//        tmp.push_back(Item(coef, head->rational, head->power));
//        irrational.erase(head);
//    }
//    irrational = tmp;

//    // step 3: sort
//    irrational.sort(cmp);
//}

Irrational::Irrational(Item item)
{
    this->irrational = {item};
    size = 1;
}

Irrational::Irrational(list<Item> irrational)
{
    this->irrational = irrational;
    size = irrational.size();
    //    simplify();
}

bool Irrational::operator==(const Irrational& ir) const
{
    if (size == ir.size)
    {
        auto ap = irrational.begin();
        auto bp = ir.irrational.begin();
        while (ap != irrational.end())
        {
            if (!((*ap) == (*bp)))
            {
                return false;
            }
            ++ap;
            ++bp;
        }
        return true;
    }

    return false;
}

std::string Irrational::toString() const
{
    string str = "";
    for (const auto& item : irrational)
    {
        str += item.coef.toString();
        str += "*";
        str += std::to_string(item.rational);
        str += "^(";
        str += item.power.toString();
        str += ") + ";
    }
    return str.erase(str.size() - 3, str.size());
}

std::ostream& operator<<(std::ostream& os, const Irrational& ir)
{
    return os << ir.toString();
}
