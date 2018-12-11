Vec3 v0(-1, -1, 0), v1(1, -1, 0), v2(0, 1, 0);
            Vec3 A = v1 - v0; // edge 0
            Vec3 B = v2 - v0; // edge 1
            Vec3 C = Cross(A, B); // this is the triangle's normal
            C.normalize();

            Vec3 N = Cross(A,B);
            N.normalize();

            Vec3 orig = ray.o - Point{0,0,0};
            Vec3 dir = ray.d;
            dir.normalize();

            if (Dot(dir, N) < 0){//verifica se a face é visivel ou nao

                float D = Dot(N, v0);

                float t = (Dot(N,orig)+ D) / Dot(N,dir);
                t = t * -1;

                Vec3 Phit = orig + dir*t;
                Vec3 P = Phit;

                Vec3 edge0 = v1 - v0;
                Vec3 edge1 = v2 - v1;
                Vec3 edge2 = v0 - v2;
                Vec3 C0 = P - v0;
                Vec3 C1 = P - v1;
                Vec3 C2 = P - v2;

                if (Dot(N, Cross(edge0, C0)) > 0 &&
                    Dot(N, Cross(edge1, C1)) > 0 &&
                    Dot(N, Cross(edge2, C2)) > 0){

                        image.setPixel( linhaPixel, colunaPixel, qRgb(0, 0, 255) );
                }
            }