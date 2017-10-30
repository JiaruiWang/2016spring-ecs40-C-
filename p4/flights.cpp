

#include "flights.h"
#include "utilities.h"

Flights::Flights() : capacity(INIT_CAP), size( 0 )
{
  flights = new Flight* [capacity];
} //

Flights::~Flights()
{
  ofstream outf ("flights2.csv");
  outf << size << endl;
  outf.close();
  outf.open("passengers3.dat", ios::trunc | ios::out);
  outf.close();

  for (int i = 0; i < size; ++i)
    delete flights[i];
  
  delete [] flights;

}  //


void Flights::addFlight()
{
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";

  for(int i = 0; i < size; i++)
    flights[i]->printFlightInfo();

  
  Flight* newFlight = new Flight();
  newFlight->addFlight();
  insert(newFlight);

}  //

void Flights::removeFlight()
{
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";
  
  for(int i = 0; i < size; i++)
    flights[i]->printFlightInfo();

  int flightNumber;
  cout << "\nFlight number to remove: ";
  cin >> flightNumber;
  cin.ignore(TEN, '\n');

  for (int i = 0; i < size; ++i)
  { 
    if (flightNumber == flights[i]->getFlightNumber())
    {

      flights[i]->removeFlight();
      delete flights[i];
      
      for (int j = 0; j < size; ++j)
      {
        if (j >= i && j < size - 1)
          flights[j] = flights[j + 1];

        if (j >= i && j == size)
          flights[j] = 0;
      }  //
      
      size--;
    } //
  } //
} //


void Flights::removePassenger() const
{
  cout << "Existing Flights:\n\n";
  cout << "Flt# Origin               Destination\n";
  
  for(int i = 0; i < size; i++)
    flights[i]->printFlightInfo();

  int flightNumber;
  cout << "\nFlight number of passenger remove: ";
  cin >> flightNumber;
  cin.ignore(TEN, '\n');

  for (int i = 0; i < size; ++i)
    if (flightNumber == flights[i]->getFlightNumber())
      flights[i]->removePassenger();
} //

void Flights::readFlights()
{
  int flightsCount;
  ifstream inf  ("flights.csv");
  inf >> flightsCount;
  inf.ignore(TEN, '\n');
 
  for(int i = 0; i < flightsCount; i++)
  {
    Flight* flight = new Flight();
    flight->readFlight(inf);
    insert(flight);
  } //

  inf.close();
} // readFlights()

void Flights::addPassenger() const
{
  int i, flightNumber; 
  cout << "Flt# Origin               Destination\n";

  for(i = 0; i < size; i++)
    flights[i]->printFlightInfo();

  do
  {
    cout << "\nFlight number (0 = exit): ";
    flightNumber = getNumber();

    if(flightNumber > 0)
    {
      
      for(i = 0; i < size; i++)
        if(flights[i]->getFlightNumber() == flightNumber)
        {
          flights[i]->addPassenger();
          break;
        }  // if found match of flight

      if(i == size)
      {
        cout << "We do not have a flight number " << flightNumber << ".\n";
        cout << "Please try again.\n";
      }  // if flightNumber not found
    }  // if flightNumber > 0
    else // if flightNumer <= 0
      if(flightNumber == ERROR)
        cout << "That is an invalid flight number.\nPlease try again.\n"; 
  }  while((flightNumber != 0 && i == size) || flightNumber == ERROR);
}  // addPassenger()


void Flights::insert(Flight* newFlight)
{
  int newNum = newFlight->getFlightNumber();
  int pos = 0;

  if (size == capacity)
  {
    capacity = capacity * RESIZE_MUL;
    Flight** newArray = new Flight* [capacity];
    // newArray 
    for (int i = 0; i < size; ++i)
      newArray[i] = flights[i];
    delete [] flights;
    flights = newArray;
  }// if the array is full, resize to twice

  if (size == 0)
  {
    flights[pos] = newFlight;
    size++;
  } //
  else //
  {
    for (pos = 0; pos < size ; ++pos)
      if (newNum < flights[pos]->getFlightNumber())
        break; // find out the right position

    for (int i = size; i >= pos; --i)
      flights[i] = flights[i - 1]; // shift i >= pos

    flights[pos] = newFlight;
    size++;
  } //
} //