
#include <mudlib.h>
#define SHIP_OBJ "/d/std/ocean/ship_ta_tong"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "Ship of Ta-Tong", "��ͨ���洬");
	add( "id", ({ "ship", "ta-tong" }) );
	set_short("��ͨ���洬");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "ocean" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"��������վ�ڴ�ͨ���洬�ļװ��ϣ���ͨ����һ��ʮ�ֳ¾ɵ��洬��\n"
"ԭ���������ں����۽������㣬�������������������صĽ�ͨԽ��Խ\n"
"Ƶ�������Դ��ϴ�͸��е���������ϾɵĴ�ͨ�žͳ��˶��֡�\n";
	switch( location ) {
		case "Deathland":
			long += "    ��ͨ��������ͣ����������ص���ͷ�ϡ�\n";
			break;
		case "Haiwei":
			long += "    ��ͨ��������ͣ���ں����۵���ͷ�ߡ�\n";
			break;
		case "ocean":
		default:
			long += "    ��ͨ����������һ���޼ʵĴ���������\n";
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
