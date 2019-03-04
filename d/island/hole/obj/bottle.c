#include <../hole.h>

inherit OBJECT;

int filled;

void create()
{
	set_name( "Empty Bottle","��ƿ��" );
	add( "id",({ "bottle" }) );
	set_short( "��ƿ��" );
	set_long( "@@query_long" );
	set( "weight",5 );
	set( "unit","��");
	filled=0;
}           

string long()
{
	if( filled )
		return "ƿ������װ��Щ��ˮ��\n";
	
	else 
		return "һ����ƿ�ӣ�Ӧ�ÿ�������װˮ��\n";
}

int query_filled(){ return filled; }

void init(){ add_action( "fill_water","fill" ); }

int fill_water(string arg)
{
	object env;
	
	if( !arg || arg!="bottle" )
		return notify_fail( "��ʲ��װˮ��\n" );
	if( filled )
		return notify_fail( "ƿ���Ѿ�װ��ˮ�ˡ�\n" );
	env=environment(this_object());
	if( living(env) ) env=environment(env);
	
	if( !env->query( "water_source" ) )
		return notify_fail( "�����ˮ�����ʡ�\n" );
	
	filled=1;
	write( "��ܿ�ؽ�ƿ��װ��ˮ��\n" );
	return 1;
}
	
