#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        ::create();
    set_level(11);
    set_name("vault guard","�ⷿ����");
    add ("id", ({ "guard" }) );
    set_short( "�ⷿ����");
        set_long( @C_LONG
һ����������վ��ֱֱ�ؿ����������ⷿ��
C_LONG
        );
    set("alignment",100);
    set( "gender", "male" );
    set( "unit", "��" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
        set_skill("polearm",30);
        set_skill("parry",55);
    set ("max_hp",350);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "silver":80]) );
    set_natural_weapon(17,10,24);
    set_natural_armor(40,22);
    set ("weight", 350);
    set("chat_chance",5);
    set("chat_output",({
        "����˵:�������������ĵط������뿪��,��Ȼ��Ҫ���泤���ޡ�\n"
       }) );
    set( "att_chat_output", ({
         "���������:�����˺þ�û����!!�����ø��һ�����ǹ��!!�µ���ȥ��!!����\n"
        }) );
 
    equip_armor(OBJS"mail01");
    wield_weapon(OBJS"lance");
}
