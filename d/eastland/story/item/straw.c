#include "../story.h"

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name("wonderful straw","��������");
        add( "id" , ({ "straw" }) );
        set_short( "��������");
        set_long(@C_LONG
һ�������ĵ����ܣ�����һͷ�и���Բ��Բ�����пյģ����������������ȡ
(suck)ĳЩ��������������Һ�塣
C_LONG  );      
        set("unit","��");
        set("weight",10);
        set("no_sale",1);
        set("value", ({500, "silver"}) );
}
void init()
{
    add_action("do_suck","suck");
}
int do_suck(string arg)
{
    object player,env,target,liquid;
    string cname;
    if ( !arg ) return notify_fail("Syntax : <suck corpse>\n");
    player=this_player();
    env=environment(player);
    if (!target=present(arg,env)) 
       return notify_fail("����û������������\n");
    cname=target->query("c_name");
    if( target->query("npc")!=SMOB"spider1" )
       return notify_fail("�������û���κ�Һ��ɹ�����ȡ��\n");
    liquid=new(SITEM"liquid");
    liquid->move(env);   
    write(sprintf("�����ɵش�%s��ȡ��һЩҺ�壡ȴ��С��Ū�������ܣ���Һ�����ڵ��ϣ�\n",cname));
    target->remove();
    this_object()->remove();
    return 1;
}