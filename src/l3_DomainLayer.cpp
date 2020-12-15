#include "hw/l3_DomainLayer.h"

using namespace std;


bool Person::invariant() const
{
    return_cost
        && !_course_name.empty() && _course_name.size() <= MAX_NAME_LENGTH
        && !_duration.empty() && _duration.size() <= MAX_NAME_LENGTH;
        && !_computer_language.empty() && _computer_language.size() <= MAX_NAME_LENGTH;
        && !_complexity.empty() && _complexity.size() <= MAX_NAME_LENGTH;
}

    Course::Course(const std::string & course_name, const std::string & duration, const std::string & computer_language,  uint16_t cost, const std::string & complexity)
    : _course_name(course_name), _duration(duration), _computer_language(computer_language), _cost(cost), _complexity(complexity)
{
    assert(invariant());
}

const string & Course::getCourseName() const
{
    return _course_name;
}

const string & Person::getLastName() const
{
    return _last_name;
}

uint16_t Person::getYearOfBirth() const
{
    return _year_of_birth;
}

bool   Person::write(ostream& os)
{
    writeString(os, _first_name);
    writeString(os, _last_name);
    writeNumber(os, _year_of_birth);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   first_name = readString(is, MAX_NAME_LENGTH);
    string   last_name  = readString(is, MAX_NAME_LENGTH);
    uint16_t year       = readNumber<uint16_t>(is);

    return std::make_shared<Person>(first_name, last_name, year);
}
