#include "../island.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level( 18 );
        set_name( "shark", "�����" );
        add( "id", ({ "shark" }) );
        set_short( "�����" );
        set_long(@LONG
���������ϲ������˺ۣ��������������ɱ�����˲����ĺۼ�������������
�����Ӻ��ˡ�
LONG
        );
        set("unit","��β");
        set_perm_stat( "str", 29 );
        set_perm_stat( "dex", 31 );
        set_perm_stat( "int", 13 );
        set_perm_stat( "kar", 28 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100);
        set( "likefish" , 1);
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":60, "none":35,"fire":35 ]) );
        set("aim_difficulty",
            ([ "vascular":66,"weakest":40 ]));
        
        set( "killer", 1 );
        set( "pursuing", 1 );
        set( "c_killer_msg","ͻȻ����Ѹ�ٵ����㱳�����˹���....");
        set( "alignment", -600 );
        set_natural_weapon( 70,30,60 );
        set_natural_armor( 78,30 );

        set_c_verbs( ({ "%s�ſ����Ĵ�ڣ�һ����%sҧȥ", "%sѸ�ٵ��Ա�����%sײȥ" }) );
        set_c_limbs( ({ "��", "����", "β��" }) );
}

void die(object killer)
{
        object ob;
        killer = query("last_attacker");
            ob = new(IOBJ"shark_wind");
          ob->move(killer);
          tell_object( killer,"�����������ַ������ȡ�£�\n");
          tell_room( environment(),
          killer->query("c_name")+"Ѹ�ٵĴ�ʬ���ϸ�����ᣬ��С���������ս����У�\n"
          ,killer);
         killer->set_explore("island#7");
         ::die();
         return;
}