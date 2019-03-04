#include <mudlib.h>

#define HP_RECOVER ({-5,8,-5,0,-5,-2,30})
#define SP_RECOVER ({20,3,2,0,30,15,0})
#define FP_RECOVER ({0,0,25,15,0,0,0})
#define TP_RECOVER ({0,15,0,20,-20,0,0}) 
#define name ({"moon herb","red berry","black_head","monk fruit","red pepper","star herb","kira fruit"})
#define ID ({"herb","berry","head","fruit","pepper","herb","fruit"})
#define c_name ({"���²�","С��ݮ","������","�޺���","����","���ǲ�","������"})
#define value ({ 250,100,200,220,100,150,200 })
#define UNITS ({ "��","��","��","��","��","��","��" })
#define POWER ({ "����","���","����","���","����","����","����" })
inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	int i;
	i = random(7);
	set_name(name[i],c_name[i]);
	add( "id" , ({ ID[i] }) );
	set_short(c_name[i]);
	set_long(
	"����һ"+UNITS[i]+"Ұ����"+c_name[i]+"�����������ж�����ֲ��ͼ��\n"
	"�����ƺ�����"+POWER[i]+"�Ĺ�Ч??\n"
	);
   	set("unit",UNITS[i]);
   	set("weight", 10);
   	set("need_skill",value[i]/5);
   	set("value",({ value[i], "silver" }) );
}

int eat_food(string arg)
{
     int i;
     string str;
     i = member_array(str,name) ;		
		if( ! arg  ) return 0;
		if ( !present(arg,this_player()) ) return 0;
		str = present(arg,this_player())->query("name");
		i = member_array(str,name) ;
		write("�����һ"+ UNITS[i] +"Ұ����"+c_name[i] +"���о�������һЩ�仯������\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"����һ"+ UNITS[i] +"Ұ����"+ c_name[i] +"������¶��һЩ��ֵı���...\n" , this_player()
		);
		this_player()->receive_healing(HP_RECOVER[i]);

	    if ((int)this_player()->query("max_sp")> 0)
	    this_player()->set("spell_points",(int)this_player()->query("spell_points")+SP_RECOVER[i]);
	    if ((int)this_player()->query("max_fp")> 0)
	    this_player()->set("force_points",(int)this_player()->query("force_points")+FP_RECOVER[i]);
	    this_player()->set("talk_points",(int)this_player()->query("talk_points")+TP_RECOVER[i]);
	    if (this_player()->query("talk_points") < 1)  
	    this_player()->set("talk_points",1);
	present(arg,this_player())->remove();
	return 1;
}

