#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name( "Main key Luoko","������Կ" );
    add("id",({"key","luoko"}) );
    set_short( "������Կ" );
    set_long(@C_LONG
�����������ҵմ���������Կ֮һ��Ҳ��Ѫͳ��֤����է��ֻ��һ�ѵ񹤾�ϸ
��С���ȣ�һ����ӵ���ǻ۵������Ӧ�����ܻ�����ǿ���Ĺ���������
C_LONG
            );
    set("unit","��");
    set("weapon_class",35);
    set("type","longblade");
    set("max_damage",5);
    set("min_damage",0);
    set("weight",100);
    set("value",({1000,"silver"}) );
    set("wield_func","daemon_wield");
    set("unwield_func","daemon_unwield");
}

void daemon_wield()
{
    if( (string)this_player()->query("class")=="scholar") {
    set("prevent_drop",1);
    set("min_damage",20);
    set("max_damage",35);
    set("extra_look","@@color");
    tell_object( this_player(),set_color(
       "\n�����ʡ���Ӧ�����ߵ��ǻۣ�������ҫ�۵Ľ�⣬�û���һ�ѳ���...\n\n"
       ,"HIY") );
    tell_room( environment(this_player()),set_color(
       "\n"+this_player()->query("c_name")+
       "���е���ԿͻȻ����ҫ�۵Ľ�⣬����һ�ѳ���...\n\n"
       ,"HIY"),this_player() );
    set_name("Main key Luoko","������Կ�����ʡ�");
    set_short("������Կ�����ʡ�");
    return;
    }
}

void daemon_unwield()
{
	object holder ;
	if ( !holder = environment(this_object()) ) return;
    if( (int)this_object()->query("wc_damaged") ){
         tell_object( this_player(),"�����е�������ԿͻȻ��ǿ��һ������ʧ������....\n");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"���е�������ԿͻȻǿ��һ������ʧ��....\n",
           this_player() );
           this_object()->remove();
           return;
           }	
    else{
    set("min_damage",0);
    set("max_damage",5);
    set("prevent_drop",0);
    delete("extra_look");
    if( (string)holder->query("class")=="scholar") {
    tell_object( holder,set_color(
       "\n�������ᣬ�����ʡ����ϵĽ����ɢȥ���ָ���ƽ����Сľ��...\n\n"
       ,"HIY") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+"������Կ�Ľ����ɢȥ...\n\n"
       ,"HIY"),holder );
    };
    set_name("Main key Luoko","������Կ");
    set_short("������Կ"); 
    return ;
    }
}                 

string color()
{
    return set_color("$N������������һ�������������γɵĽ�ɫ����...\n","HIY");
}
