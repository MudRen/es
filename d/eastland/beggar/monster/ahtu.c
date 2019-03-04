#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
    ::create();
    set("lvlimit",15);
    set_level(7);
    set_name( "countryman ahtu", "������" );
    add( "id",({"ahtu","countryman"}) );
    set_short( "ׯ�ں� ������");
    set_long(@C_LONG
�����д���һ�������Ķ��亹��,¶�����������ֵĴ�׳�ֱ�, �ֱ��ϲ��¼�ǧ��
�����̡��Ӱ������·����ƶ���¶����������, ����ϡ���Կ���һ����������,��
���ǰ�����ƽʱ���ڹ����Ľ���� �����챻��������( hurt )����·���������
̧��ҩ��������Сѩ�ӵ�Ϥ�����ơ� 
C_LONG
            );
    set("unit","λ");
    set("gender","man" );
    set("race","human");      
    set("age",45);
    set_perm_stat( "dex", 14 );
    set_perm_stat( "str", 16 );
    set_perm_stat( "int", 7 );
    set_perm_stat( "con", 13 );
    set_perm_stat( "piety", 5 );
    set_perm_stat( "karma", 10 );
    set ("max_hp", 250);
    set ("hit_points", 250);
    set ("wealth", ([ "silver": 60 ]) );
    set_natural_weapon( 19, 10, 18 );
    set_natural_armor( 15, 2 );
    set ("weight", 550);
    set ("exp_reward", 1150 );
    set("chat_chance",2);
    set("chat_output",({
            "�����в�����������:��Ӵ,��ʹӴ��\n",
            "�����в�����������:��֪���Ͳ�Ҫ���������\n"
    }) );
    set("inquiry", ([
             "hurt":"@@ask_hurt"
    ]) );
}        
void ask_hurt(object asker)
{
    tell_object(asker,
     "������̾��:��,������ȥ��ǣ��硻����ʱ���������,������Ĳ�֪��\n"
     "           ������ʲ�ᶫ��,Ȼ�ᱻѹ���ڵ��ϡ�������������ʱ��,��\n"
     "           ��֪����˭���������صĿ���һ��, �Ҿͻ赹�ˡ�����ʱ��\n"
     "           ��������, ��һ��û�к��˽��,��������᡺�䡻? ��Ӵ,\n"
     "           ��ʹӴ��\n"
       );
}
