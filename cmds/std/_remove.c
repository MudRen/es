//#pragma save_binary

#include <mudlib.h>

inherit DAEMON ;

int cmd_remove(string str)
{
	object obj, *ob;
	string name;
	int i, class1 ;

  	notify_fail("ж��ʲ��װ����\n");
	if(!str || str == "")  return 0;

	// Added by Annihilator@Eastern.Stories 10-28-93
	if( str=="all" ) {
		this_player()->block_attack(6);
		ob = all_inventory(this_player());
		i = sizeof(ob);
		while(i--) {
			if( !ob[i]->query("equipped") ) continue;
			if( undefinedp(ob[i]->query("armor_class")) && 
			    undefinedp(ob[i]->query("defense_bonus")) )
				continue;
			ob[i]->unequip();
		}
		write( "��ж������װ������л��ס�\n" );
		write("Ok.\n");
		return 1;
	}

	obj = present(str,this_player()) ;
	if( !obj )
		return notify_fail("������û���κν��� "+str+" �Ķ�����\n"
		) ;

	class1 = obj->query("armor_class");
	if ( undefinedp(class1) && undefinedp(obj->query("defense_bonus")) ) 
		return notify_fail("�ǲ��ǻ��ס�\n") ;

	if (obj->query("equipped")) {
// Unequip it in this case.
// The unequipping code is in the armor object because several commands
// (drop, dest, give) can force the player to unwield the weapon and they
// all need access to it. The player can only wield the weapon using the
// wield command, so that code is a command.
		obj->unequip() ;
		this_player()->block_attack(6) ;
		return 1 ;
	}

	return notify_fail("�㲢û�а�"+obj->query("short")+"װ�������ϡ�\n"
	) ;
}

int help() {
	write (@HELP
ʹ�ø�ʽ: remove <������>

�ѵ���װ���ķ���.

���ָ��: wear, wield, unwield
HELP
);
	return 1 ;
}
