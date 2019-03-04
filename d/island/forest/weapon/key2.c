#include "../tsunami.h"

inherit WEAPON;

void create()
{
        set_name( "Main key Janser","������Կ");
        add( "id", ({ "key","janser"}) );
        set_short( "������Կ");
        set_long(@C_LONG
�����������ҵմ���������Կ֮һ��Ҳ��Ѫͳ��֤����է��ֻ��һ�ѵ񹤾�ϸ
��С���ȣ�һ������˼ϸ��������Ӧ�����ܻ�����ǿ���Ĺ���������
C_LONG
        );

        set("unit", "��" );
        set("weight", 100 );
        set("type","dagger" );
        set("weapon_class",30 );
        set("max_damage",5);
        set("min_damage",0);
        set("value", ({1000, "silver" }) );
        set("wield_func","daemon_wield");
        set("unwield_func","daemon_unwield");
}

void daemon_wield()
{
    if( (string)this_player()->query("class")==("healer") || 
        (string)this_player()->query("class")==("mage") ||
        (string)this_player()->query("class")==("thief") ){
    set("prevent_drop",1);
    set("min_damage",18);
    set("max_damage",32);
    set("extra_look","@@color");
    tell_object( this_player(),set_color(
       "\n�����롻��Ӧ����ϸ�����˼��������ҫ�۵����⣬�û���һ��ذ��...\n\n"
       ,"HIC") );
    tell_room( environment(this_player()),set_color(
       "\n"+this_player()->query("c_name")+
       "���е���ԿͻȻ����ҫ�۵����⣬����һ��ذ��...\n\n"
       ,"HIC"),this_player() );
    set_name("Main key Janser","������Կ�����롻");
    set_short("������Կ�����롻");
    return;
    }return;
}

void daemon_unwield()
{
	object holder;
	if ( !holder=environment(this_object()) ) return;
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
    if( (string)holder->query("class")==("healer") ||
        (string)holder->query("class")==("mage") ||    
        (string)holder->query("class")==("thief") ){
   tell_object( holder,set_color(
      "\n�������ᣬ�����롻���ϵ�������ɢȥ���ָ���ƽ����Сľ��...\n\n"
      ,"HIC") );
   tell_room( environment(holder),set_color(
      "\n"+holder->query("c_name")+
      "������Կ��������ɢȥ.......\n\n"
      ,"HIC"),holder );
    };
   set_name("Main key Janser","������Կ");
   set_short("������Կ");
   return;
   }
}       

string color()
{
   return set_color("$N��������������һ��ϸ������ɫذ�ף���ʱ����ҫ�۵Ĺ�â...\n","HIC");
}

    