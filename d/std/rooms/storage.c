#include "/d/mage/mage.h"
inherit ROOM;
 
void create()
{
	::create();
	set_short("������");
	set_long(@LONG
����һ��С������, �����ħ��ʦ�ǽ�����Ҫ��װ�������ڴ�, ����
������ħ��ʦ��ʹ�á����޵ۻ��ص��ڷ������ڴ�����һ��ħ������,
�Է����������ð��ħ��ʦǱ��͵ȡ���ڴ˴�����Ʒ��
LONG
	);

	set("exits", ([
		"up"	: MAGE"hall_of_fame",
		]) );

	set("class_name","mage") ;	
	set("clean_msg1",
	    "�����ҹ���Ա%s�����:���̫�ණ����, ������һ����ٷš�\n");
	set("msg_arg1","��������");
	set ("light", 1);
}

int receive_object(object arg)
{
    string msg ;
    object *contents;
//    ::receive_object(arg) ;   
    if(living(arg)) return 1 ;    
     if (base_name(arg)=="/std/statue") return 1;
    contents = all_inventory(this_object());
    if(sizeof(contents) >60) 
       {
           tell_object(this_player(),
                       sprintf(query("clean_msg1"),query("msg_arg1"))) ;     
           return 0 ;
        }
   else 
	{
	tell_room(environment(this_player()),"һ���ɫ��â������"+arg->query("c_name")+"��Ȼ�ὥ����ʧ�ˡ�\n");
	arg->delete("value");
	return 1;
	}
}
int clean_up() { return 0; }
