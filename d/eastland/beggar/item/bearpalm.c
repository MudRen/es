#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat_me" );
}

void create()
{
        
	set_name("Bear Palm","���������ơ�");
	add( "id" , ({ "palm","bear palm" }) );
        set_short(set_color("���������ơ�","CYN"));
        set_long(@C_LONG
�ѵ�һ���ļ��ȣ����㲻���������Σ�ʳָ��(eat_me palm)��
C_LONG
	);
   	set("unit","��");
   	set("weight", 50);
   	set("value",({ 800, "gold" }) );
}

int eat_food(string arg)
{
        
    if( !arg || ( arg != "palm") )
        return notify_fail("��Ҫ��ɶ����?\n");
    this_player()->add_temp("drink_nest_times",1);
    if( this_player()->query_temp("drink_nest_times")>5 ) {
       tell_object(this_player(),
         "Ӵѽ�����������һֻ"+set_color("���������ơ�","CYN")+"֮���Ȼ��ʼ"+
         set_color("����Ѫ","HIR")+"�������ǲ���ͷ�ˡ���\n");
       tell_room( environment(this_player()),"Ӵѽ��"+
         this_player()->query("c_name")+
         "����һֻ"+set_color("���������ơ�","CYN")+"֮���Ȼ��ʼ"+set_color("����Ѫ","HIR")+
         "�������ǲ���ͷ�ˡ���\n",
         this_player());
       this_player()->delete_temp("drink_nest_times");
       BLEEDING->apply_effect(this_player(),20,1);    
       remove();
       return 1;
    }
    tell_room( environment(this_player()),"��վ���Ա�����ˮ�ؿ���"+
        this_player()->query("c_name")+"����һֻ"+set_color("���������ơ�","CYN")+"����\n", 
         this_player());
    tell_object( this_player(),
        "������س���һֻ"+set_color("���������ơ�","CYN")+"���ţ��óԡ���\n");
    this_player()->set("hit_points",this_player()->query("max_hp") );
    this_player()->set("force_points",this_player()->query("max_fp") );
    remove();
    return 1;
}
