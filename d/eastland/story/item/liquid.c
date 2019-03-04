#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

int left_times=3;
void create()
{
        set_name("poison liquid","�����롹��Һ");
        add( "id" , ({ "liquid" }) );
        set_short( "�����롹��Һ");
        set_long(@C_LONG
һЩ�ɡ����롹���ϴ���ȡ�����Ķ�Һ����˵���ⶾҺ�ܽ�ٶ�����������ԺȺ�
��(drink_liquid)�������������еĶ���
C_LONG  );      
        set("unit","��");
        set("weight",10);
        set("drink_liquid",1);
        set("no_sale",1);
        set("value", ({100, "silver"}) );
}
void init()
{
    add_action("do_drink","drink_liquid");
}
int do_drink(string arg)
{
    object player;
    player=this_player();
    left_times--;
    if( !player->query("conditions/simple_poison") ) {
       write("��ѽ������˶�Һ֮���Ȼ�ж��ˣ�\n");
       (CONDITION_PREFIX + "simple_poison")->apply_effect( player, 10 , 5 );
       return 1;
    }
    tell_object( player, 
       "����¡����롹��Һ֮�ᣬ����Զ�������˲���������еĶ���ȫ������ˣ�\n");
    SIMPLE_POISON->remove_effect(player);
    player->add("hit_points",-10);
    if (left_times<0) {
       write("���������һ��ʱ��ȴ�����Ѿ�û��ʣ�����Ķ�Һ�ˣ�\n");
       this_object()->remove();
    }
    return 1;
}