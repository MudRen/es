#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("ghost-killed spell","��ħ��");
        add( "id" , ({ "spell" }) );
        set_short( "��ħ��");
        set_long(@C_LONG
����д��һ������ģ�����һ�����ģ������ĵ���˼��(spell_use)��
C_LONG  );      
        set("unit","��");
        set("weight",10);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_spell","spell_use");
}
int do_spell(string arg)
{
    object player,env;
    player=this_player();
    env=environment(player);
    tell_room(env,sprintf(
      "��ħ����%s���з���������ʧ춵��ϡ�\n",player->query("c_name")),player);
    tell_object(player,"\n��ħ���������з���������ʧ춵��ϡ�\n\n");
    env->set("trap_set",1);
    this_object()->remove();
    return 1;
}