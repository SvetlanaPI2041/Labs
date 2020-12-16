#include "hw/l3_DomainLayer.h"

using namespace std;


bool Course::invariant() const
{
    return_cost >= MIN_YEAR_OF_BIRTH
        && _cost <= MAX_YEAR_OF_BIRTH
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

const string & Course::getDuration() const
{
    return _duration;
}

const string & Course::getComputerLanguage() const
{
    return _computer_language;
}

uint16_t Course::getCost() const
{
    return _cost;
}

const string & Course::getComplexity() const
{
    return _complexity;
}


bool   Course::write(ostream& os)
{
    writeString(os, _course_name);
    writeString(os, _duration);
    writeString(os, _computer_language);
    writeNumber(os, _cost);
    writeString(os, _complexity);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   course_name = readString(is, MAX_NAME_LENGTH);
    string   duration  = readString(is, MAX_NAME_LENGTH);
    string   computer_language  = readString(is, MAX_NAME_LENGTH);
    uint16_t cost       = readNumber<uint16_t>(is);
    string   complexity   = readString(is, MAX_NAME_LENGTH);

    return std::make_shared<Course>(course_name, duration, computer_language, cost, complexity);
}
