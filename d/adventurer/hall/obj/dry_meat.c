#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("dry meat","����Ǭ");
	add( "id" , ({ "meat" }) );
	set_short("dry meat" , "����Ǭ");
	set_long( 
		"����һ�鲻֪ʲ�ᶫ�����ɵ���Ǭ����������һ��һ����ʳ�ν�\n"
		"���������֪��ζ�����Ǻܺã������ܿ��Ա���ܾá�\n"
	);
   	set("heal",1);
   	set("unit","��");
   	set("weight", 10);
   	set("value",({ 1, "silver" }) );
}
int eat_food(string arg)
{
     object me;
     int num1,num2;
		me = this_player();
		if( !arg || arg != "meat" ) return notify_fail("��ʲ��?\n");
		write( "���������������Ǭ���ۣ����̣��������ٻ������������..\n" );
                tell_room( environment(me),
                "�㿴��"+me->query("c_name")+"�����Ŀ���һ����Ǭ"
                "��һ��¶����ֵı���...\n" , this_player());
                num1 = query("heal");
                num2 = num1/2+10;
		me->receive_healing(num1);
	        me->add("talk_points",-num2);
// Eat too much meat tp <0 will sick
// add by Iris@ES Feb 6 1996	        
	if (me->query("talk_points")<0) {
		write("��������Ǭ�Զ������, ��������岻̫���...\n");
		(CONDITION_PREFIX+"sick")->apply_effect(me,3,2,2);
	}		        
       if ( query("rotten") != 1 ) {
        remove();
        return 1;
        }
       write( "��֣�����������ʱ��̫��������о��е㲻���...\n");
       (CONDITION_PREFIX + "weak")->apply_effect(me,6,5);
	remove();
	return 1;
}

