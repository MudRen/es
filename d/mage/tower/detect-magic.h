// This is a spell to let caster can detect magic items	by Yueh 1995/4/6
#include <mudlib.h>

#define TYPE "misc"

string *magic_name =
    ({ "fire","cold","electric","energy","mental","acid","poison","magic","evil","devine","none" });
string *magic_c_name =
    ({ "��","��","��","��Դ","����","��","��","ħ��","а��","��ʥ","����" });

string *magic_name1 =
    ({ "fire","cold","electric","energy","evil","none" });

string *magic_c_name1 =
    ({ "������","������","������","��̫֮��","������","������" });

string identify_armor(object obj, int skill)
{
	int sp_def,i;
	string msg;
	if ((obj->query("armor_class")) || (obj->query("defense_bonus"))) {
	if (obj->query("special_defense") ) {
		msg="";
		for (i=0; i<11; i++){
		sp_def=(int)obj->query("special_defense/"+magic_name[i]);
		if ( sp_def ) {
			if (random(2)==0) 
				sp_def=sp_def+(random(108- skill))/2;
			else 	sp_def=sp_def-(random(108- skill))/2;
			msg+="������߶�"+magic_c_name[i]+"ϵ��ħ��";

			if (sp_def > 60) msg+="��������˼��ķ�����ǿ��\n";
			else if (sp_def > 38) msg+="����ʮ�������ķ�����ǿ��\n";
			else if (sp_def > 28) msg+="�����ǳ������ķ�����ǿ��\n";
			else if (sp_def > 18) msg+="���������ķ�����ǿ��\n";
			else if (sp_def > 8) msg+="���������ķ�����ǿ��\n";
			else if (sp_def >= 0) msg+="������΢�ķ�����ǿ��\n";
			else if (sp_def >= -8) msg+="������΢�ķ���ȱ�ݡ�\n";
			else if (sp_def >= -18) msg+="���������ķ���ȱ�ݡ�\n";
			else if (sp_def >= -28) msg+="�������صķ���ȱ�ݡ�\n";
			else if (sp_def >= -38) msg+="����ʮ�����صķ���ȱ�ݡ�\n";
			else  msg+="��������˼��ķ���ȱ�ݡ�\n";
		}
		}
	return msg;
	}
	else return("�������û���κ�ħ���������ԡ�\n");
	}
	else return("�����Ʒ���Ƿ��ߡ�\n");

}

string consider_magic(object dest, int skill)
{
	int sp_def,i;
	string msg;
	msg="";
	for (i=0; i<6; i++){
		sp_def=(int)dest->query_special_defense(magic_name1[i]);
		write(sp_def);
		if (random(2)==0) 
			sp_def=sp_def+(random(110- skill))/2;
		else 	sp_def=sp_def-(random(110- skill))/2;
		msg+="��������"+magic_c_name1[i]+"�Ĺ���";

		if (sp_def > 80) msg+="��������˼��ķ���������\n";
		else if (sp_def > 60) msg+="����ʮ�������ķ���������\n";
		else if (sp_def > 40) msg+="�����ǳ������ķ���������\n";
		else if (sp_def > 20) msg+="���������ķ���������\n";
		else if (sp_def >= 10) msg+="��������ķ���������\n";
		else if (sp_def >= 0) msg+="����һЩ�ķ���������\n";
		else if (sp_def >= -10) msg+="�����ܲ�ķ���������\n";
		else if (sp_def >= -20) msg+="�����ǳ���ķ���������\n";
		else if (sp_def >= -40) msg+="����ʮ�ֲ�ķ���������\n";
		else  msg+="����û�з���������\n";
	}
	return msg;

}

