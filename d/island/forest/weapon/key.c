/*
 * ԭ���ߣ�Tsunami (1995.1)
 * �޸��ߣ�Ishige (1995.12)
 */

#include "../tsunami.h"

inherit HOME+"magic";
inherit WEAPON  ;

void create()
{
    set_name( "Main key Tsunami","������Կ" );
    add("id",({"key","tsunami"}));
    set_short( "������Կ" );
    set_long(@C_LONG
�����������ҵմ���������Կ֮һ��Ҳ��Ѫͳ��֤����է��ֻ��һ�ѵ񹤾�ϸ
��С���ȣ�һ����ӵ�������������Ӧ�����ܻ�����ǿ���Ĺ���������
C_LONG
            );
    set("unit","��");
    set("weapon_class",45);
    set("type","jousting");
    set("second",1);
    set("max_damage",2);
    set("min_damage",1);
    set("weight",100);
    set("value",({1000,"silver"}) );
    set("special_damage",5);
    set("wield_func","knight_wield");
    set("unwield_func","knight_unwield");
}


void knight_wield()
{
    
    if( (string)this_player()->query("class")=="knight") {
//        set("hit_func","my_hit"); 
        set("prevent_drop",1);
        set("min_damage",25);
        set("max_damage",45);
        set("extra_look","@@color");
        tell_object(this_player(),  set_color(
       "\n�������ȡ���Ӧ�����������������ҫ�۵���⣬�û���һ�ѳ�ǹ...\n\n",
       "HIG") );
        tell_room( environment(this_player()),set_color(
       "\n"+this_player()->query("c_name")+
       "���е���ԿͻȻ����ҫ�۵���⣬����һ�ѳ�ǹ...\n\n"
       ,"HIG"),this_player() );
        set_name("Main key Tsunami","������Կ�������ȡ�");
        set_short("������Կ�������ȡ�");
        return;
    }
}

void knight_unwield()
{
	object holder;
	if ( !holder=environment(this_object())) return;
    if( (int)this_object()->query("wc_damaged") ){
           tell_object( this_player(),"�����е�������Կ����һ��ǿ�������ʧ������....\n");
           tell_room(environment(this_player()),
         this_player()->query("c_name")+"���е�������ԿͻȻǿ��һ������ʧ��....\n",
           this_player() );
           this_object()->remove();
           return;
           }
    else{
         delete("hit_func","my_hit");
         set("min_damage",1);
         set("max_damage",2);
         set("prevent_drop",0);
         delete("extra_look");
         if( (string)holder->query("class")=="knight") {
          tell_object(holder, set_color(
           "\n�������ᣬ�������ȡ����ϵ������ɢȥ���ָ���ƽ����Сľ��...\n\n"
           ,"HIG") );
          tell_room( environment(holder), set_color(
           "\n"+holder->query("c_name")+"������Կ�������ɢȥ...\n\n"
           ,"HIG"),holder );
          };
        set_name("Main key Tsunami","������Կ");
        set_short("������Կ"); 
        return;
        }
}                 

int my_hit(object victim,int dis)
{
	int my_pie,vi_pie,dam;
	object holder;
	string v_name,m_name;

	if( !victim) return 0;
	if( !(holder=environment( this_object() )) || !living(holder) )
		return 0;

	my_pie = (int)holder->query_stat("pie");
	vi_pie = (int)victim->query_stat("pie");     
	dis = (int)query("special_damage"); 
	/* ��һֻ pie=20 �Ĺ�����ԣ�damage=30 */
	dam = (dis + my_pie) * 2 - vi_pie;
	v_name = victim->query( "c_name" );
	m_name = holder->query( "c_name" );

	if( !holder->query_temp("mounting") ) return 0;
	/* һ�� pie=20 �� knight ʹ��ʱ���ع�����Ϊ 1/5 */
	if( random(60) > my_pie ) return 0;
	tell_room(environment(victim),set_color(
	"\n������ԿͻȻɢ��һ����⣬��Ƭ���������Χ�� "+v_name+" ������.......\n\n","HIG") );
	victim->receive_special_damage( "none", dam );
	victim->set("last_attacker",holder);   
	report(holder,victim);
	return dam;
}

string color()
{
return set_color("$N����������һ���ۼ��������γɵ���ɫ��ǹ...\n","HIG");
}    
