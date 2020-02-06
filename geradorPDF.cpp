// basic file operations
// Desenvolvido por Manollo Castro de Pinho Martinez
// Gerador de tabela MPDF em c++ que gera um arquivo de nome example.php contendo Programação Orientada a Objeto, CSS.

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define TAB 9

using namespace std;

vector<string>myvector;

int main () {
  ofstream myfile;
  myfile.open ("example.php");

	//---------------------------------------------------------------------------------------------------------------------------//
  	myfile << "<?php\n";
  	myfile << endl;
  	myfile << endl; 
  	myfile << "require_once('../../../php/core/main.php');\n";
  	myfile << "require_once ('../../../php/core/checkSession.php');\n";
 	myfile << "include("; myfile << '"'; myfile << "../../../admin/sistema/mpdf/mpdf.php"; myfile << '"'; myfile << ");\n";

	//---------------------------------------------------------------------------------------------------------------------------//

	myfile << "\n";
	myfile << "\n";

	cout << "Quantas Classes Deseja Inserir?" << endl;
	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		string nome;
		cout << "Classe: " << i+1 << endl;
		cin >> nome;
		/*for ( int j = 0; j < nome.length(); j++)
    	cout << nome[j] << " - " << (int)nome[j] << endl;
  		cout << endl;*/
		myfile << "$_"; myfile << nome; myfile<<"_class = new "; myfile << nome; myfile << "();\n";
		myvector.push_back(nome);
	}

	myfile << "\n";
	myfile << "\n";

	for(int z = 0; z < myvector.size(); z++){
		if(z == 0){
			myfile << "$id_"; myfile << myvector[z]; myfile << " = sanitize($link, 'id');\n";
		}
		myfile << "$"; myfile << myvector[z]; myfile << " = "; myfile << "$_"; myfile << myvector[z]; myfile <<"_class -> trazer_por_id("; myfile << "$id_"; myfile << myvector[z]; myfile << ");\n";

	}

	myfile << "\n";
	myfile << "\n";

	myfile << "$_HTML = "; myfile <<  '"'; myfile << "\n"; myfile << "\n";
	myfile << "<style>\n";
	myfile << "#anexo-iv tr {\n";
	myfile << "line-height: 2rem;\n";
	myfile << "text-transform: uppercase;\n";
	myfile << "}\n";

	myfile << "\n";

	myfile << "td {\n";
	myfile << "text-transform: uppercase;\n";
	myfile << "}\n";

	myfile << "\n";

	myfile << "#container {\n";
	myfile << "display: block;\n";
	myfile << "margin: 0 auto;\n";
	myfile << "}\n";

	myfile << "\n";

	myfile << "#container hr {\n";
	myfile << "border-top: 1px solid black;\n";
	myfile << "}\n";

	myfile << "\n";

	myfile << "</style>\n";

	myfile << "\n";
	myfile << "\n";


	myfile << "<htmlpagefooter name='MyFooter1'>\n";
	myfile << "<table width='100%"; myfile << "' style='vertical-align: bottom; font-family: serif; font-size: 9pt; color: #000000; font-weight: bold; font-style: italic;'>";
	myfile << "	<tr>\n";
	myfile << "<td>\n";

	cout << "Qual o nome da Empresa do Projeto? " << endl;
	string empresa;
	cin >> empresa;
	myfile << "<td>"; myfile << empresa; myfile <<"</td>\n";
	cout << "Qual o Endereco?" << endl;
	string endereco;
	getline(std::cin >> std::ws, endereco);
	myfile << "<td align='center'> "; myfile << endereco; myfile << "</td>\n";
	myfile << "<td>Pag. {PAGENO}/{nbpg}</td>\n";
	myfile << "</td>\n";
	myfile << "</tr>\n";
	myfile << "</table>\n";
	myfile << "</htmlpagefooter>\n";
	myfile << "<sethtmlpagefooter name='MyFooter1' value='on' />"; myfile << '"'; myfile << ";\n"; 
	myfile << "$_HTML .= "; myfile <<  '"'; myfile << "\n"; myfile << "\n";
	myfile << "<htmlpageheader name='MyHeader1'>\n";
	myfile << "<table align='center' border=0 cellpadding=0  cellspacing='0' width='100%' style='margin-bottom:20px;'>\n";
	myfile << "<tr>\n";
	string caminho;
	//cin.ignore();
	cout << "Digite aqui o Caminho da Logo da Empresa" << endl;
   	getline(std::cin >> std::ws, caminho);
	myfile << "<td align='left' ><img src='"; myfile << caminho; myfile << "'height='8%' border=0></td>\n";
	myfile << "<td align='right'"; myfile << " width=15>"; myfile << ".date('d/m/Y H:i:s')."; myfile << " </td>\n";
	myfile << "</tr>\n";
	myfile << "</table>\n";
	myfile << "</htmlpageheader>\n";
	myfile << "<sethtmlpageheader name='MyHeader1' value='on' show-this-page='1' />"; myfile << '"'; myfile << ";\n";
	myfile << "\n";
	myfile << "\n";

	cout << "Sua Tabela tem Cabecalho?" << endl;
	cout << "0 - SIM" << "      "  << "1 - NAO" << endl;
	bool escolha;
	cin >> escolha;

	myfile << "$_TABLE = "; myfile <<  '"'; myfile << "\n"; myfile << "\n";
	myfile << "<table id='tabela-sucesso' border='1' cellpadding='2' cellspacing='0' style='width:100%;' aria-describedby='example_info' class='table table-striped table-bordered dataTable'>\n";
	int lines = 0, col = 0;

	if(escolha == 0){
		string title;
		//cin.ignore();
		cout << "Digite aqui o Titulo da sua Tabela" << endl;
	    getline(std::cin >> std::ws, title);	
		cout << "Quantas linhas tera o cabecalho da sua tabela" << endl;
		cin >> lines;
		myfile << "<thead>\n";
		myfile << "\n";
		for(int k = 0; k < lines; k++){
			myfile << "<tr>\n";
			cout << "Quantas colunas tera a linha " << k + 1 << " o cabecalho da sua tabela" << endl;
			cin >> col;
			for(int n = 0; n < col; n++){
				cout << "Defina Linha: " << k + 1 << " Coluna: " << n + 1 << endl;
				string create;
				//cin.ignore();
				getline(std::cin >> std::ws, create);
				myfile << " <th style='text-align: center;' colspan='3'> "; myfile << create << " </th>\n";
			}
			myfile << "</tr>\n";
		}
		myfile << "</thead>\n";
	}
	
	myfile << "<tbody>\n";
	int lines_body, col_body;
	cout << "Quantas linhas tem as Celulas de Dados da sua Tabela?" << endl;
	cin >> lines_body;
	for(int k = 0; k < lines_body; k++){
		myfile << "<td>\n";
		cout << "Quantas colunas tera a linha " << k + 1 << "da sua tabela" << endl;
		cout  << "OBS: MAX DE 3 COLUNAS" << endl;
		cin >> col_body;
		for(int n = 0; n < col_body; n++){
				cout << "Defina Linha: " << k + 1 << " Coluna: " << n + 1 << endl;
				string create;
				//cin.ignore();
				getline(std::cin >> std::ws, create);
				myfile << "<td style='text-align: left;' colspan='3'>"; myfile << create << " bancoSQL </td>\n";
		}
		myfile << "</td>\n";
	}
	myfile << "</tbody>\n";
	myfile << "</table>\n";

	myfile << "<br>\n";
	myfile << "<br>"; myfile << '"'; myfile << ';'; myfile << "\n";
	myfile << "$_TABLE .= "; myfile <<  '"'; myfile << "</b>.\n";
	myfile << "<br>\n";
	myfile << "<br>\n";
	myfile << "</ul>\n";
	myfile << "</div>\n"; myfile << '"'; myfile << ";\n";
	myfile << "\n";
	myfile << "\n";
	myfile << "\n";
	myfile << "\n";

	myfile << "$_HTML .= "; myfile <<  '"'; myfile << "<sethtmlpageheader name='MyHeader1' value='on' show-this-page='1'/><sethtmlpagefooter name='MyFooter1' value='on'/></table>"; myfile << '"'; myfile << ";\n";
	myfile << "$mpdf = new mPDF('utf-8', 'A4-P', '11', '', 10, 10, 30, 20, 5, 0);\n";
	myfile << "$mpdf->allow_charset_conversion=true;\n";
	myfile << "$mpdf->SetHTMLHeaderByName('MyHeader1');\n";
	myfile << "$mpdf->SetHTMLFooterByName('MyFooter1');\n";
	myfile << "$mpdf->WriteHTML($_HTML);\n";
	myfile << "$mpdf->Output('arquivo.pdf', 'I');\n";

	myfile << "\n";
	myfile << "\n";
	myfile << "\n";
	myfile << "\n";

	myfile << "?>";

  myfile.close();
  return 0;
}
