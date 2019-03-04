#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  ���������Ϊ���ε������� realname ���ǳɹ��ı�ʶ�ᴫ�ص�����     
        
	set_short("@@query_c_name");    
        
        set("c_realname","��֥");           // ��ұ��ϳɹ����ص�����
        set("realname","great mushroom");
	
   	set("unit","��");                     // ��,��,��.�����

   	set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

   	set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��
      
        set("herb_file","great_mushroom.c") ;//���������Ķ�������������
        set("herb_path","/d/healer/reagent/");//���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant
                                                
        set("skill_require",70) ;             //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",2);                    //���ܲɼ���
       
        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;
  
  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;
   
  if (this_player()->query_stat("int") < 10 ) {
    set("id",({"plant","tree"}) );
    set_name("a plant","����ֲ��");
    set_long("��������ֲ�����κ�һ����ƺ���Щ��ͬ, ��ϧ����򵥵�С�Դ���,\n"
             "����˵��������Ȼ����\n");
    return "����ֲ��";
  }
  else if ( ok==1 ) {
    set("id",({"plant","tree","great mushroom","mushroom"}) );
    set_name("great mushroom","��֥");
    set_long("��������ϸ�����Ľ��, ���ж�����һ����֥(great mushroom),\n"
             "�������ҩ��, ��������(dig)һ���ȥ��\n");
    return "��֥";
}
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","ަ��ֲ��");
    set_long("�������ڹ�������α��е�����֪ʶ, ���ж�����һ��ަ��ֲ��, \n"
             "������ȷ������, ����Ҫ��һ���ı�ʶ��\n");
    return "ަ��ֲ��";
  }
}      


