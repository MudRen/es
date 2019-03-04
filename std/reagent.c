//#pragma save_binary

#include <mudlib.h>
#include <conditions.h>
inherit OBJECT;

// This is inherit file for reagents.
// reagents can set the following attributes:
//  1. savour /ζ��/
//       legal values are acidity    ��
//                        bitter     �� 
//                        acrimony   ��
//                        sweet      ��
//  2. effects => can be set to simple_poison, weak or slow
//  3. if effect is set to simple_poison then the following 
//     need to be setted
//
//     duration => how many times to be poisoned
//     damage   => hp lost in each duration 
//
//  4. if effect is set to weak or slow, then need to set 
//     the following
//                          
//     frequency => how many heart beats to recover 1 time
//     difference=> how many str or dex to be decreased.

void init()
{
  add_action("do_taste","taste");
}
  
int do_taste(string str)
{
   int duration;
   int damage;
   object me;
   
        seteuid(getuid());
	if( !id(str) ) return notify_fail(
		"��Ҫ����ʲ�ᶫ����\n");

        if ( query("savour")=="bitter") {
          write( 
                 "�㽫" + query("c_name") + "������߳���,��!!������!!\n");
        }else if ( query("savour")=="acidity") {
          write( "��С�ĵ�����һ��"+query("c_name")+", ����, ���ᰡ!!\n");
        } else if ( query("savour")=="acrimony" ){
          write( "�����������"+query("c_name")+"һ��....��!!�������!!�ġ���ˮ??");
        } else if (query("savour")=="sweet") {
          write ("��������"+query("c_name")+",��,���������!Ī���Ƕ�ҩ����?\n");
	} else {
	  write ( "�㳢�˳�" + query("c_name") +",���о������ر��ζ����\n");
	}  
	if ( query("effect")=="simple_poison") {
	  duration=(int)query("duration");
	  damage=(int)query("damage");
          me = this_player();
        ("/std/conditions/simple_poison")->apply_effect(me,duration,damage);
	}else if ( query("effect")=="weak") {
	  duration=(int)query("frequency");
	  damage=(int)query("difference");
          me = this_player();
        ("/std/conditions/weak")->apply_effect(me,duration,damage);
	}else if ( query("effect")=="slow") {
	  duration=(int)query("frequency");
	  damage=(int)query("difference");
          me = this_player();
        ("/std/conditions/slow")->apply_effect(me,duration,damage);
	} else {	
	write(
		"�㽫" + query("c_name") + "������ߡ��ԣ���û�ио�ʲ���������á�\n");
	}
	
	tell_room( environment(this_player()),
		this_player()->query("c_name") + "��" + query("c_name") + "������ߡ��ԡ�\n",
		this_player() );
	return 1;
}
