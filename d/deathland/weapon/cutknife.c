
#include "../echobomber.h"
inherit OBJECT;

void create()     
{
	seteuid(getuid());
	set_name( "cutknife", "���С��" );
	set_short("���С��");
	set_long( 
	   "һ�Ѻ�������С��,�ƺ����Ǳ������ӡ����ϸ���(cut)����ĺù���.\n"
	    );
	add("id", ({ "knife", }));
	set( "unit", "��" );
	set("weight", 30);
	set("no_sale",1);
	set("value", ({ 0, "copper" }));
}


void init()
{
	add_action("cut_ear", "cut");
}

int cut_ear(string str)
{
	string str1,str2;
	object room_1,ob1,ob2;
	
    if (!str) return 0;
    if (sscanf(str,"%s from %s",str1,str2)!=2) {
      write("�﷨����: cut A from B.\n");
      return 1;
	  }
	if( str1!="ear") return 0;
    if( str2!="corpse") return 0;
    room_1=environment(this_player());
    if ( ( ob1=present(str2,room_1) ) )
      if ((int)(ob1->query("troll_ear"))==1) {   
         if (!(ob1->query("be_cut")))
           {
           write("��Ӿ��˵ġ����ϸ����˶���.\n");
           ob2=new(Object"/trollear");
           ob2->move(this_player());
           ob1->set("be_cut",1);
           }
         else 
         write("������Ѿ������������.\n");
         }
      else
         {
         write("�����??��һ�������⵫���ƺ�������߲���.\n");
         }
    else
    write("����û���κΡ���.\n");
    
    return 1;

}
