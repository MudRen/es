#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(16);
        set_name( "white lion","������ʨ" );
        add("id",({"lion"}));
        set_short( "������ʨ" );
        set_long(@C_LONG
����һֻë���ྻ��������覵�ʨ�ӡ��������ʹ�ľ��ˣ������оŸ��˵Ķ�λ��
����������ʨ���춼�Ǵ�춼���״̬�����Ը����ײ��ޱȣ�����һ������Ķ���
��Ҫ�ú���Ūһ�㣬ʹ֮��ƣ������Ȼ������֮�븹�ſϰ��ݣ���ѽ���㷢������
��ʨ���������˹�����
C_LONG
        );
        set("unit","ֻ");
        set_perm_stat( "str", 28 );
        set_perm_stat( "int", 12 );
        set_skill( "dodge", 60 );
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        set( "killer", 1 );
        set( "c_killer_msg","��ͻȻ����������ʨ�ſ�������������˹���....");
        set( "alignment", -500 );
        set_natural_weapon(28,18,29);
        set_natural_armor(60,15);
        set_c_verbs( ({ 
           "%s�ſ����Ĵ�ڣ�һ����%sҧȥ",
            "%sѸ�ٵ���%s��ȥ",
           "%s�Ӷ�������צ����%sץȥ"}) );
        set_c_limbs( ({ "ͷ��", "����", "�Ų�" }) );
}
