#include <mudlib.h>
#define SHIP_OBJ "/d/std/cloud/airship_pegasus"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "airship pegasus", "����ŷ���");
	add( "id", ({ "airship", "pegasus" }) );
	set_short("����ŷ���");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "cloud" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"��������վ������ŷɴ��ļװ��ϣ������޴��Φ�˳�����������ɫ�ľ޷���ռ\n"
"ȥ�˷ɴ��᷽һ���Ŀռ䣬���ҷɴ�ԭ����Ĭ��˹�˽�����������ʵ۵������\n"
"����춻ʵ۶�Ĭ��˹�˲������Σ����ҷɴ�շת����һ��ŵ���������˵����У�����\n"
"���Ѿ����˸��е������������ٵĽ�ͨ���ߡ�\n";
	switch( location ) {
		case "Easta":
			long += "    �����������ͣ����ᰳ���������ؿ�վ��\n";
			break;
		case "Nodania":
			long += "    �����������ͣ��ŵ�����ǳ�����ؿ�վ��\n";
			break;
		case "cloud":
		default:
			long += "    �������������������������С�\n";
			break;
	} 
	return long;
}

// This function sets the location of the ship.
varargs void set_location( string new_loc, string exit )
{
	location = new_loc;
	if( location=="cloud" || !exit ) {
		set( "exits", ([]) );
		SHIP_OBJ->move( "/d/std/cloud/cloud" );
	} else {
		set( "exits", ([ "out": exit ]) );
		SHIP_OBJ->move( exit );
	}
}
