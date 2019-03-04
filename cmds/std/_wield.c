//#pragma save_binary

// _wield.c
// Command to wield weaponry.
// Mobydick@TMI-2, 9/11/92
// Modify by Kyoko@EasternStories 09/20/94

#include <mudlib.h>
#include <weapons.h>

inherit DAEMON;

int help();

int cmd_wield(string str, int silent)
{
	object usr, obj, firstwep, secondwep, shield;
	string type;
	int class1, weight, chinese_mode, i;
    
	if( !str ) return help();
	usr = this_player();
	chinese_mode = can_read_chinese();

	usr->block_attack(2);
	obj = present( str,usr );
	if( !obj ) return notify_fail(
		sprintf("�������û���κν���%s�Ķ�����\n",str));

	class1 = obj->query("weapon_class");
	type = obj->query("type");
	
	if( member_array(type, WEAPON_TYPES) == -1 || !class1 )
		return notify_fail("�ǲ�����������\n");
			
	if( class1 > 15 ) {
		if( usr->query_perm_skill(type) < class1 * 2 )
		     return notify_fail( sprintf(
			"���%s���ܻ�������ʹ��������������\n",to_chinese(type)));
	}
	
	weight = obj->query("weight");
	if( weight > (int)usr->query_stat("str") * 10 + 30 )
		return notify_fail(
			"���������������̫���ˡ�\n"
		);

	if( obj->stop_wield( usr ) ) return 0;

	firstwep = usr->query("weapon1");
	secondwep = usr->query("weapon2");
	shield = usr->query("armor/shield");
	
	if( obj==firstwep || obj==secondwep )
		return notify_fail ("���Ѿ�װ����������ˡ�\n");

	if( firstwep && secondwep )
		return notify_fail ("�����ֻ��ͬʱװ������������\n");

	if( firstwep && shield )
		return notify_fail("Ҫװ���ڶ��������������ճ�һֻ�֡�\n"
		);
	
	if( !firstwep && !secondwep ) {
		if( shield && (int)obj->query("nosecond")==1 )
			return notify_fail("�������������˫�ֲ���ʹ�á�\n"
			);

		if( !silent ) {
			write( sprintf("��װ��%sΪ������\n",obj->query("short")));
			tell_room( environment(usr), 
				sprintf("%sװ��%s��Ϊ������\n",
					usr->query("c_name"),obj->query("short")), usr);
		}
		
		usr->set("weapon1", obj);
		obj->wield();
		return 1;
	}

	// If we got here, the player is already wielding one weapon.
	if( firstwep->query("nosecond") )
		return notify_fail("���Ѿ�װ������Ҫ˫�ֵ������ˡ�\n"
		);

	if( obj->query("nosecond") )
		return notify_fail(sprintf("%s��Ҫ��˫��ʹ�á�\n",obj->query("short"))
		) ;

	if( !obj->query("second") && !firstwep->query("second") )
		return notify_fail("�㲻��ͬʱʹ��������Ҫ������\n"
		);

	if( (int)obj->query("second") ) {
		usr->set("weapon2", obj);
		if( !silent )
			write(sprintf("��װ��%sΪ��Ҫ������\n",obj->query("short")));
	} else {
		usr->set("weapon2", firstwep);
		usr->set("weapon1", obj);
		if( !silent )
			write(sprintf("���%s����������Ҫ������\n",firstwep->query("short")));
			write(sprintf("����%s����Ҫ������\n",obj->query("short")));
        if(firstwep->query("wield_func"))
          {  call_other(firstwep,firstwep->query("wield_func")) ; }
	}
	
	// if we got here, we have wielded the weapon. 
	if( !silent )
		tell_room( environment(usr), 
			sprintf("%sװ��%s��Ϊ������\n" ,
			usr->query("c_name"),obj->query("short")), usr);
	
	obj->wield();
	return 1;
}

int help()
{
	write (@HELP
ָ���ʽ: wield <����>

���ָ������װ��ĳ��������Ϊ����. ��������װ����������, ��ĳЩ
������Ϊ������ʹ�÷����Ĺ�ϵ������Ҫ�õ���ֻ��. ����, ��Ҳ����һ
���ö�һ����˫������.

���ָ��: wear, remove, unwield.
HELP
	);
	return 1 ;
}
