#include <mudlib.h>
#include <stats.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
	set_name("sausage","��һ���㳦��");
	add( "id" , ({ "sausage" }) );
   set_short("��һ���㳦��");
   set_long(@C_LONG
һ��������������㳦,������ʳָ�󶯡�
C_LONG
	);
   	set("unit","��");
        set("weight", 15);
   	set("value",({ 300, "silver" }) );
}

int eat_food(string arg)
{
        
    if( !arg ||( arg != "sausage") ) 
        return notify_fail("��Ҫ��ɶ����?\n");
    tell_room( environment(this_player()),this_player()->query("c_name")+
        "���̻����س�����һ����һ���㳦��,��������û�Զ���������...\n", 
         this_player());
    tell_object( this_player(),
        "�����̻����س�����һ����һ���㳦��,�������Ƕ��ˡ���\n");
    this_player()->receive_healing( 15+random(5) );
    remove();
    return 1;
}
