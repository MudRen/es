#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "icy sword", "������" );
	add( "id", ({ "sword" }) );
	set_short( "an icy sword", "������" );
	set_long(
		"You see a shortsword made by ice crystal  .\n",
	"����һ�Ѵ�˵�е��潣����������ͨ��͸���Ľ����˵������������\n"+
	"������Ȼǿ�糤�괵Ϯ���ɣ�����ܹ��в������޼᲻�ݣ���������\n"+
	"˵����������������������ܵõ���ʱ�����˺͵���ϣ����в���˼\n"+
	"������鷢����\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	setup_weapon( "shortblade", 30, 15, 30 );
	set( "value", ({ 300, "gold" }) );
        set("no_sale",1);
}
