#include "matrix.hpp"  

matrix::matrix(){
    cout<<"la matriz no puede ser inicializada"<<endl;
    cout<<"set matriz 1x1";
    row=1;
    colum=1;
    M=new float*[1];
    M[0]=new float[1];
    M[0][0]=1;
    }

matrix::matrix(int r,int c){
    if(r>1 && c >1){
        row=r;
        colum=c;
        M=new float*[row];
        for(int i=0;i<colum;i++){
            M[i]=new float[colum];
            for(int j=0;j<colum;j++)
                M[i][j]=0;
        }
    }
    else{
        cout<<"Matriz::class Error!"<<endl;
        cout<<"Dimension no valida"<<endl;
    }
}

matrix::matrix(const matrix&in_M){
    row=in_M.row;
    colum=in_M.colum;

    M=new float * [row];
    for(int i=0;i<row;i++)
        M[i]=new float [colum];

    for(int i=0;i<row;i++)
        for(int j=0;j<colum;j++)
            M[i][j]=in_M.M[i][j];
}

matrix::~matrix(){
    if(row>0){
        delete []M;
    }
    row=0;
    colum=0;
}
    
matrix matrix::operator*(const matrix &in_matrix){
    matrix out_matrix(row,in_matrix.colum);
    for(int i=0;i<row;i++)
        for(int j=0;j<in_matrix.colum;j++)
            for(int k=0;k<colum;k++)
                out_matrix.M[i][j]+=M[i][k]*in_matrix.M[k][j];
    return out_matrix;
}

matrix matrix::operator=(const matrix &in_matrix){
    if(this != &in_matrix){
        delete [] M;
        row=in_matrix.row;
        colum=in_matrix.colum;
        M= new float* [row];
        for(int i=0;i<row;i++)
            M[i]=new float [colum];

        for(int i=0;i<row;i++)
            for(int j=0;j<colum;j++)
                M[i][j]=in_matrix.M[i][j];
    }
    return *this;
}


matrix matrix::operator+(const matrix &in_matrix){
    matrix out_matrix(row,colum);
    if(row==in_matrix.row)
        if(colum==in_matrix.colum)
        {
            for(int i=0;i<row;i++)
                for(int j=0;j<colum;j++)
                    out_matrix.M[i][j]=M[i][j]+in_matrix.M[i][j];
        }
    else
        cout<<"Dimensiones de matrices incorrectas"<<endl;
    return out_matrix;
}

matrix matrix::operator - (const matrix &in_matrix) {
	matrix out_matrix(row, colum);
	if (row == in_matrix.row)
		if (colum == in_matrix.colum)
		{
			for (int i = 0; i < row; i++)
				for (int j = 0; j < colum; j++)
					out_matrix.M[i][j] = M[i][j] - in_matrix.M[i][j];
		}
		else
			cout << "Dimensiones de matrices incorrectas" << endl;
	return out_matrix;
}

ostream& operator<<(ostream& out,const matrix& p_matrix){

    char aux=' ';
     for(int i=0;i<p_matrix.row;i++)
char aux=' ';

    for(int i=0;i<p_matrix.row;i++)	
         for(int j=0;j<p_matrix.colum;j++){
             if(j==p_matrix.colum-1)
                 aux='\n';
             else
                 aux=' ';
             out<<p_matrix.M[i][j]<<aux;
         }
         
    return out;
}

istream& operator>>(istream& in, const matrix& p_matrix){
int count=0;

    for(int i=0;i<p_matrix.row;i++){
        for(int j=0;j<p_matrix.colum;j++){
            cout<<"Elemento["<<i+1<<"]["<<j+1<<"]:";
            in>>p_matrix.M[i][j];
        }
		cout<<endl;
    }

    return in;
}
