#include "../../story.h"

inherit OBJECT;

void create()
{
        set_name("dragon wood","����׮");
        add( "id" , ({ "wood" }) );
        set_short( "����׮");
        set_long(@C_LONG
����һ�����κ�������ľͷ�����������滹���˺ܶ�������������˼��
(use_dragon_wood)��
C_LONG  );      
        set("unit","��");
        set("weight",10);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_use","use_dragon_wood");
}
int do_use(string arg)
{
    object player,env;
    string name;
    player=this_player();
    env=environment(player);
    name=player->query("c_name");
    tell_room(env,sprintf(
      "%s�������еĶ���׮��˲�䣬һ������%s����������ʧ춿ռ䣡\n",name,name),player);
    tell_object(player,"��������еĶ���׮����Ȼ����һ��������������\n");
    player->move_player(SCITY"house3","SNEAK");
    tell_room(environment(player),sprintf("һ������%s�����˵أ�\n",name),player);
    this_object()->remove();
    return 1;
}