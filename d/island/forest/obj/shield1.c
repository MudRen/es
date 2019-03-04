#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Hawk Shield","��ӥ��");
    add("id",({"shield"}));
    set_short("��ӥ��");
    set_long(@LONG
�����������Ҹ���Ѫͳ��֤����Ψ��ӵ��ħ���ߣ�����ӵ����ΰ����ʥ
������������������������ǿ���ħ����������֧�䣬���Բ�����һ
������������֧��ġ�
LONG
            );
    set("unit","��");
    set("no_clean",1) ; 
    set("type","shield");
    set("material","element");
    set("armor_class",6);
    set("defense_bonus",1);
    set("special_defense",(["all":10,"none":0]) );
    set("weight",100);
    set("no_sale",1);
    set("value",({1500,"silver"}) );
    set("equip_func","daemon_wear");
    set("unequip_func","daemon_unwear");
}



void daemon_wear()
{
    if( (string)this_player()->query("race")=="daemon" ||
        (string)this_player()->query("class")=="mage"  ||
        (string)this_player()->query("class")=="healer"   ) {
      if( (int)this_player()->query_level() < 13){
        tell_object( this_player(),
        "���ħ��̫С��������ʹ�ܽ�������չ����....\n");
        }
        else{
    set("prevent_drop",1);
    set("armor_class",8);
    set("defense_bonus",4);
    set("light",1);
    set("extra_look","@@color");
    set("special_defense",(["all":50,"none":30]) );
    write( set_color(
       "\n��ӥ�ܺ�Ӧ�����ħ��������չ����Ƭ�޴�Ĺ���£�������ǰ��...\n\n"
       ,"HIW") );
    tell_room( environment(this_player()),set_color(
       "\n��ӥ�ܻ�������"+this_player()->query("c_name")+
       "����ǰ��չ����Ƭ�޴�Ĺ���.........\n\n"
       ,"HIW"),this_player() );
    set_name("Hawk Wind","��ӥ��");
    set_short("��ӥ��");
        }
    return;
    } 
    return;
}

void daemon_unwear()
{
	object holder;
	if ( !this_object() ) return ;
	if ( !holder=environment(this_object()) ) return;
//    holder=this_player();
    if( (int)holder->query_level() >= 13){
    set("armor_class",6);
    set("defense_bonus",1);
    set("light",0);
    delete("extra_look");
    set("prevent_drop",0);
    if( (string)holder->query("race")=="daemon"  ||
        (string)holder->query("class")=="mage"  ||
        (string)holder->query("class")=="healer" ) {
    tell_object( holder,set_color(
       "\n�������ᣬ��Ƭ�޴�Ĺ���������ɢȥ���ָ���ƽ���Ĺ�ӥ��...\n\n"
       ,"HIW") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+
       "��ǰ����Ƭ����������ɢȥ���ָ���ƽ���Ķ�...\n\n"
       ,"HIW"),holder );
    };
    set_name("Hawk Shield","��ӥ��");
    set_short("��ӥ��"); 
    return;
    }
    else return;
}                 

string color()
{ 
  return set_color("$N����ǰ£������Ƭ�޴�������Ĺ�����������Ӣͦ����...\n","HIW");
}