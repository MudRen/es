#include <../mumar.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(17);
        set_name( "fight horse", "ս��" );
        add( "id", ({ "horse" }) );
        set_short( "ս��" );
        set_long(
        "����һƥ�ߴ�ǿ׳����ΰ�ĺ�ɫ�����ս����վ���Ա߾����Լ�����һ�ء�\n"
        "�����������(mount) ������ս���ϱ��ۣ�һ��������һ�����¡�\n");
        set( "unit", "ƥ" );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 76,39 );
        set_skill("dodge",80);
        set( "alignment", 300 );
        set( "extra_look","$N������һƥ���������ս��������һ������������ӡ�\n");
        set( "mountable", 1);
        set( "max_load", 2300 );
        set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
        set_c_verbs( ({ "%ş�����ȣ���%sһ��", "%s������������ǰ֫��%sһ���Ҳ�"}) );
        equip_armor(OBJS"saddle");
}
void init()
{
        mount::init();
}
