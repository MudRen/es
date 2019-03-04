#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
  add_action("eat_pill","eat");
}  
void create()
{
	set_name("dragon pill", "������" );
	add( "id", ({"pill"}) );
	set_short("������");
	set_long(
		"����ҩ�������������Ĳ�ҩ, ����ҷ���ҩ��ɵ����岻��:p\n"
		"������Ч����������ͷ���ۻ�, ���������̳�(eat)һ������\n"
		"��������������Ѿ�����, ���ֲ�ҩ�������β�, �㻹��Ӧ��ȥ\n"
		"��ҽ����\n"
	);
	set( "can_eat", 1 );
	set( "unit", "��" );
	set( "weight", 15 );
	set( "value", ({ 3000, "silver" }) );
}

int eat_pill(string str)
{
    int stat;
    object player;
        
        if (!str || str!="pill") 
          return notify_fail("��Ҫ��ʲ��?\n");
        player=this_player();
	stat = (int) player->query("medication_resistance");
	// 1 dragon pill can recover from 3 makira potion
	stat = stat - 210 ;
	if (stat<0) stat=0; 
	player->set("medication_resistance",stat);	
        tell_object(player,"���������״���ö���, ͷҲ���������Ρ�\n");
        remove();
        return 1;
}
