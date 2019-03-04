#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level( 6 );
        set_name( "artisan", "����" );
        set_short("����" );
        set_long(
                "�⹤������ͷרע�ع�����ûע����ĵ�����\n"
        );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set( "alignment", 200 );
        set( "defense_type","berserk" );
        set( "max_hp", 150 );
        set( "hit_points", 150 );
        set( "wealth/silver", 30 );
        set( "tactic_func", "my_tactic" );
        set_natural_weapon( 7, 3, 4 );
        set_natural_armor( 38, 10 );
        wield_weapon( OBJS"hammer" );
}
int my_tactic(int damage)
{
        object victim, armor;
        if( random(20)>10 && (armor=victim->query("armor/shield")) ) {
        tell_room( environment(), ({
                "������Ц�ؿ���" + victim->query("c_cap_name") + "��" +
                armor->query("c_name") + "������ॡ�һ��������ȥ��\n"}),
                ({ environment(), victim }) );
        tell_object( victim,
                "������Ц�ؿ������" +
                armor->query("c_name") +"������ॡ�һ��������ȥ��\n" );
 
        if( !armor->query("ac_damaged") )
            armor->set_short((string)armor->query("short") + " (damage)",
            (string)armor->query("c_short") + " (����)" );
 
        if( (int)armor->query("armor_class") > 1 )
                 armor->add( "ac_damaged", 1 );
                 victim->calc_armor_class();
        }
return 0;
}
