#include "geoRecord.h"

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for FileManager class.

Parameters:	none
Pre:		none
Post:		none
*/
geoRecord::geoRecord()
{
	offset = 0; 
	xcoord_dms = 0.0; 
	ycoord_dms = 0.0; 
	totalx = 0.0;
	totaly = 0.0;
	fileid = 0;

}
	
//////////////////////////////////////////////////////////////// setOffset()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setOffset(unsigned int offs)
{
	offset = offs;
}

//////////////////////////////////////////////////////////////// getOffset()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
int geoRecord::getOffset()
{
	return offset;
}

//////////////////////////////////////////////////////////////// setFid()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setFid(string fileId)
{
	fid = fileId;
}

//////////////////////////////////////////////////////////////// getFid()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
string geoRecord::getFid()const
{
	return fid;
}	

//////////////////////////////////////////////////////////////// intFid()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
int geoRecord::intFid()
{
	
	fileid = atoi(getFid().c_str());
	return fileid;
}

//////////////////////////////////////////////////////////////// setState()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setState(string s)
{
	state = s;
}

//////////////////////////////////////////////////////////////// getState()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
string geoRecord::getState()const
{
	return state;
}

//////////////////////////////////////////////////////////////// setCounty()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setCounty(string c)
{
	county = c;
}

//////////////////////////////////////////////////////////////// getCounty()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
string geoRecord::getCounty()const
{
	return county;
}

//////////////////////////////////////////////////////////////// setCell()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setCell(string ce)
{
	cell = ce;
}

//////////////////////////////////////////////////////////////// getCell()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
string geoRecord::getCell()const
{
	return cell;
}

//////////////////////////////////////////////////////////////// getName()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setName(string n)
{
	name = n;
}

//////////////////////////////////////////////////////////////// setName()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
string geoRecord::getName()const
{
	return name;
}

//////////////////////////////////////////////////////////////// setCoordx()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setCoordx(double x)
{
	xcoord_dms = x;
}

//////////////////////////////////////////////////////////////// setCoordy()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
void geoRecord::setCoordy(double y)
{
	ycoord_dms = y;
}

//////////////////////////////////////////////////////////////// getCoordx()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>	
double geoRecord::getCoordx()
{
	return xcoord_dms;
}

//////////////////////////////////////////////////////////////// getCoordy()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>	
double geoRecord::getCoordy()
{
	return ycoord_dms;
}

//////////////////////////////////////////////////////////////// totalSecx()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>	
void geoRecord::totalSecx(double x) //converting x coordinate to seconds
{
	totalx = x;
}

//////////////////////////////////////////////////////////////// totalSecy()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>	
void geoRecord::totalSecy(double y) //converting y coordinate to seconds
{	
	totaly = y;
	
}

//////////////////////////////////////////////////////////////// getTotalx()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
double geoRecord::getTotalx()
{
	return totalx;
}

//////////////////////////////////////////////////////////////// getTotaly()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
double geoRecord::getTotaly()
{
	return totaly;
}
//////////////////////////////////////////////////////////////// operator<<()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
ostream& operator<<(ostream& out, geoRecord* rec)
{
	out << "[" << rec->getFid()<< "," << rec->getOffset() << "]" << endl;
	return out;
}

//////////////////////////////////////////////////////////////// operator<<()
// Operator overloader for outputtin
//
// Parameters:  string Code
//
// Pre:       none
//
// Post:      
//
// Returns:  const Accession& rhsx
//
// Called by: 
// Calls: none
ostream& operator<<(ostream& out, geoRecord rec)
{
	out << "[" << rec.getFid()<< "," << rec.getOffset() << "]" << endl;
	return out;
}

//////////////////////////////////////////////////////////////// operator<()
// Operator overloader for less than.
//
// Parameters:  string Code
//
// Pre:       none
//
// Post:      
//
// Returns:  const Accession& rhsx
//
// Called by: 
// Calls: none
bool geoRecord::operator<(const geoRecord& rhs)const
{
        return (getFid() < rhs.getFid());
}

//////////////////////////////////////////////////////////////// operator<()
// Operator overloader for greater than
//
// Parameters:  string Code
//
// Pre:       none
//
// Post:      
//
// Returns:  const Accession& rhsx
//
// Called by: 
// Calls: none
bool geoRecord::operator>(const geoRecord& rhs)const
{
        return (getFid() > rhs.getFid());
}

bool geoRecord::operator==( geoRecord& rhs)
{
	return (intFid() == rhs.intFid());
}
/////////////////////////////////////////////////////////
//                ****DECONSTRUCTORS****
//
//	
geoRecord::~geoRecord()
{
	
}

