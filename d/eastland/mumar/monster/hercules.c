#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(15);
        set_name( "Hercules", "��ʿ" );
        add ("id", ({ "hercules", "yang" }) );
        set_short( "��ʿ" );
        set_long(
    "����ص���ʿ����ս����ͨ���ǵ���ǰ���ְ��������ɵ��˵��ش���ʧ��\n");
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 10 );
        set_perm_stat( "int", 15 );
        set ("wealth", ([ "gold": 50 ]) );
        set_natural_weapon(10,14,17);
        set_natural_armor(75,35);
    set ("weight", 300);
    set( "pursuing",1 );
    set ("chat_chance", 10);
    set( "att_chat_output", ({
        "��ʿ�߻�����ͷ�߿�Ц�������Ұ����������\n"
        }));
    set("c_death_msg","%s �Ӵ����������һ�Σ���ͨһ�����������ϣ�������ѹ��..\n");
    set_skill("blunt",60);
    set_skill("parry",70);
    wield_weapon(OBJS"hammer1");
}
