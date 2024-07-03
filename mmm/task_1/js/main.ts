interface Teacher {
    readonly firstName: string;
    readonly lastName: string;
    fullTimeEmployee: boolean;
    yearsOfExperience?: number;
    location: string;
    [key: string]: any; // Index signature to allow additional properties
}

interface Directors extends Teacher {
    numberOfReports: number;
}

interface printTeacherFunction {
  (firstName: string, lastName: string): string;
}

export function printTeacher(firstName: string, lastName: string): string {
  return `${firstName[0]}. ${lastName}`;
}

// Define a new interface for StudentClass constructor
interface StudentClassConstructor {
    firstName: string;
    lastName: string;
}

// Define interface for StudentClass
interface StudentClass {
    workOnHomework(): string;
    displayName(): string;
}

// Implement StudentClass
class Student implements StudentClass {
    private firstName: string;
    private lastName: string;

    constructor({ firstName, lastName }: StudentClassConstructor) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    workOnHomework(): string {
        return 'Currently working';
    }

    displayName(): string {
        return this.firstName;
    }
}
