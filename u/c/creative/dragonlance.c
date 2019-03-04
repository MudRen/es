#include <mudlib.h>

inherit WEAPON;

string C_NAME="����ǹ";

void create()
{
        seteuid(getuid());
        set_name( "lance of dragon", C_NAME );
        add( "id", ({ "lance", "dragonlance" }) );
        set_short( "��ǹ ����ǹ" );
        set_long(
                "������ҵĴ���֮��,��������֮��������Ϊ��Ҫ\n"
                "��˵����ǹ�����ſ��µ�ħ��Ϊ��,�������һ���൨���ҵ������ǹ�ͻ�\n"
                "��������µ�ħ��,��˵ǹ��������������ս!\n"
        );
        set( "unit", "��" );
        set( "type", "jousting" );
        set( "weapon_class", 49 );
        set( "min_damage", 35 );
        set( "max_damage", 60 );
        set( "weight", 220 );
        set( "hit_func", "weapon_hit" );
        set( "value", ({ 5600, "silver" }) );
        set( "no_sale", 1 );
}


int weapon_hit(object victim,int dam)
{
        object holder;
        int align,max;
        string him,me,bonus;

        if ( !victim ) return 0;
        if( !holder = environment(this_object()) || !living(holder) ) return 0;
        else {
                /* �������⹥�����˺��� */
                align=holder->query( "alignment" );
                if( align >= 150000 ) { dam=40; }
                else if( align < 150000 ) { dam=35; }
                else if( align < 100000 ) { dam=30; }
                else if( align < 45000 ) { dam=25; }
                else if( align < 15000 ) { dam=20; }
                else if( align < 4500 ) { dam=15; }
                else if( align < 1500 ) { dam=10; }
                
                if ( random(50) < 10 ) {
                        if ( (int)holder->query( "spell_points" )< 5 ) {
                                tell_object( holder,set_color( "��ľ��������ٻ�������ħ....\n","HIR" ) );
                                return 1;
                        }
                        
                        him=victim->query( "c_name" );
                        me=holder->query( "c_name" );
                        tell_object( holder,set_color(
                                "�����ϵ�","HIW")+C_NAME+set_color("ͻȻ�ɳ����л���һ����������"+him+"��\n","HIW") );
                        tell_object( victim,set_color(
                                me+"���ϵ�","HIW")+C_NAME+set_color("�ɵ����л���һ����������Ϯ����\n","HIW") );
                        tell_room( environment(holder),set_color(
                                me+"���ϵ�","HIW")+C_NAME+set_color("�ɵ����л���һ����������"+him+"��\n","HIW"),({ holder,victim }) );
                        victim->receive_special_damage( "cold",dam );
//                      report( victim );
                        holder->add( "spell_points",-5 );
                        victim->set( "last_attacker",holder );
                        return dam;
                }
        return 0;
        }
}
