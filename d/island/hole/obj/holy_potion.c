#include <../hole.h>

inherit OBJECT;
void create()
{
	set_name( "Holy Potion","ʥˮ" );
	add( "id",({ "holy potion","potion" }) );
	set_short( "ʥˮ" );
	set_long(@LONG
	һƿʥˮ��ר�������Ը���Ѫ��ġ�
LONG
		);
	set( "weight",5 );
	set( "unit","��");
}           

void init(){ add_action( "to_throw","throw" ); }

int to_throw(string arg)
{
	string what,which;
	
	if( !arg || sscanf(arg,"%s to %s",what,which)!=2 )
		return notify_fail( "Usage: throw <item> to <target>\n" );
	if( which!="vampire" )
		return notify_fail( "ʥˮ�������ף������������\n" );
	if( what!="potion" )
		return notify_fail( "�ⶫ��������������ร�\n" );
		
	write( set_color(
"��˦��˦�ֱۣ�������ʥˮ����Ѫ������ȥ����ƫ���д�����Ѫ�������ϡ�\n","HIY") );
	this_object()->remove();
	return 1;
}
	