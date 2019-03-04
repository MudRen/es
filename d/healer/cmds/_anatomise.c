//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int cmd_anatomise(string str)
{
    object weapon;
	string text, name;
	int skill, exp, level, n;
	object targ, env, me, bild;
	mixed *ids;
	int i,j;
	int is_corpse;
	string *info, corpse, target;
	int difficulty;
	mapping data;
    
    	if (!str) return notify_fail("��Ҫ����ʲ�᣿\n");
	seteuid(getuid());
	data = ([]);
	info = explode( read_file("/d/healer/cmds/anatomise.dat"), "\n" );
	j=0;
	for( i=0; i<sizeof(info); i++ ) {
		// Skip comments
		if( info[i][0]=='#' ) continue;
		if( sscanf(info[i], "[%d]%s=%s", difficulty, corpse, target)==3 ) {
			data[j] = ({difficulty, corpse, target});
	        j++;
	    }
	}        
	me = this_player();
	weapon=(object) me->query("weapon1");
	if (!weapon || (string)weapon->query("type")!="dagger") {
	   tell_object(me,"������û���ʵ��Ĺ���, �޷����н��ʡ�\n");
           return 1;
	}   
	env = environment(me);
	if( !env || !targ = present(str, env) )
		return notify_fail("��Ҫ���ʵĶ�����������\n");

	skill = (int)this_player()->query_skill("anatomlogy");
	if( !skill ) 
	    return notify_fail( "����!ûѧ������ѧ�����Ҹ���!!\n");

    if (! targ->id("corpse")) {    
	  tell_object(me,"�������?����������ܽ�����!!\n");
	  tell_room( env, 
	        sprintf("%s�������,��Ȼ��ͼ����%s��\n",
		me->query("c_name"),targ->query("c_name")), me);
       return 1;	              
	}
	bild=new("/d/healer/reagent/corpse1.c");
	bild->move(environment(me));
    for (i=0;i<sizeof(data);i++) {
      if (random(skill) < data[i][0]) continue;
      if (targ->id(data[i][1])) {
        targ->remove();
        bild=new(data[i][2]);
        bild->move(me);
        tell_object(me,sprintf("��ϲ��,�ɹ���ȡ��һ%s%s�ˡ�\n",
	bild->query("unit"),bild->query("c_name")));
        tell_room(env,
	sprintf("%s��ʬ�����ó�һ%s%s��\n",
		me->query("c_name"),bild->query("unit"),bild->query("c_name")),me);
        return 1;                      
      }
    }  
	tell_object(me,"���ʬ��ȫ��������,��Ȼ�Ҳ������õĶ�����\n");
	tell_room( env, 
		sprintf("%s��%s��ʬ������һͨ��\n" ,me->query("c_name"),weapon->query("c_name")),me );
    targ->remove();
	return 1;
}

int help()
{
  write(
  @C_HELP
ָ���ʽ: anatomise <����>

���ָ�������ĳ���ض�������ʡ�
���ָ���Ķ�����ʬ��, ��ʬ�������м�ֵ�Ķ���, ����Զ�
ȡ����
C_HELP
  );
  return 1;
}
