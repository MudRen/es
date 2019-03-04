
#include <mudlib.h>
#define SHIP_OBJ "/d/std/ocean/ship_death"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "ship of darkmerchant", "�ڰ����˺�");
	add( "id", ({ "ship", "darkmerchant" }) );
	set_short("�ڰ����˺�");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "ocean" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"��������վ�ںڰ����˺ŵĴ���, һ���е��ƾ��ֲ���̫�ƾɵ����ʹ�, һ������\n"
"������ɫ�������ĻҰ�ɫ�İߵ�, ���Ե����Ҵ��ƺ���ʻ��ֲ��ĵط���\n";
	switch( location ) {
		case "Bluesand":
			long += "    �ڰ����˺�������ͣ������ɳ�۵���ͷ�ϡ�\n";
			break;
		case "Deathland":
			long += "    �ڰ����˺�������ͣ����������ص���ͷ�ߡ�\n";
			break;
		case "ocean":
		default:
			long += "    �ڰ����˺�������������һ���޼ʵĴ��ϡ�\n";
			break;
	} 
	return long;
}

// This function sets the location of the ship.
varargs void set_location( string new_loc, string exit )
{
	location = new_loc;
	if( location=="ocean" || !exit ) {
		set( "exits", ([]) );
		SHIP_OBJ->move( "/d/std/ocean/ocean" );
	} else {
		set( "exits", ([ "out": exit ]) );
		SHIP_OBJ->move( exit );
	}
}
